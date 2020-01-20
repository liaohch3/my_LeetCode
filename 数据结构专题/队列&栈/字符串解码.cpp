#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    string decodeString(string s){
        return decode(0, s);
    }

    string decode(int index, string s){
        int times = 0;
        string res = "";
        for(int i = index; i < s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                times = times * 10 + s[i] - '0';
            }
            else if(s[i] == '['){
                string temp = decode(i+1, s);
                for(int j = 0; j < times; j++)
                {
                    res += temp;
                }
            }
            else if(s[i] == ']')
            {
                return res;
            }
            else{
                res.push_back(s[i]);
            }
        }
        return res;
    }

};


int main()
{

    return 0;
}