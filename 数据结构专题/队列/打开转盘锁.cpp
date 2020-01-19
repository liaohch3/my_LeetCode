#include <iostream>
#include <vector>
#include <set>
// #include <pair>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:

    bool dead(set<string>& sdeadends, string str){
        return sdeadends.find(str) != sdeadends.end();
    }

    vector<string> makeStrings(string str, set<string>& sdeadends, set<string>& visited)
    {
        vector<string> res;
        for(int i = 0; i < 4; i++)
        {
            char temp = str[i];
            if(str[i] == '9')
                str[i] = '0';
            else
                str[i]++;

            if(!dead(sdeadends, str) && visited.find(str) == visited.end())
            {
                res.push_back(str);
                visited.insert(str);
            }

            str[i] = temp;

            if(str[i] == '0')
                str[i] = '9';
            else
                str[i]--;           

            if(!dead(sdeadends, str) && visited.find(str) == visited.end())
            {
                res.push_back(str);
                visited.insert(str);
            }

            str[i] = temp;
        }
        return res;
    }

    int openLock(vector<string>& deadends, string target) {


        set<string> sdeadends;
        for(int i = 0; i < deadends.size(); i++)
            sdeadends.insert(deadends[i]);

        if(dead(sdeadends, "0000"))
            return -1;

        if(target == "0000")
            return 0;

        string str("0000");
        queue<string> q;
        set<string> visited;
        q.push(str);
        visited.insert(str);
        int num = 0;

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                string front = q.front();
                // cout << front << endl;
                if(front == target)
                    return num;
                q.pop();
                vector<string> next = makeStrings(front, sdeadends, visited);
                for(int j = 0; j < next.size(); j++)
                {
                    //if(visited.find(next[j]) == visited.end())
                    {
                        q.push(next[j]);
                        //visited.insert(next[j]);
                    }
                }
            }
            // cout << endl;
            num++;
        }
        return -1;
    }
};

int main(){

    string ss[] = {"0000"};
    vector<string> deadends(ss, ss+1);
    string target("8888");

    Solution solution;
    cout << solution.openLock(deadends, target) << endl;


    return 0;
}
