#include <iostream>
#include <vector>
#include <set>
// #include <pair>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:

    int numSquares(int n) {

        if(n == 1)
            return 1;

        queue<int> q;
        set<int> visited;
        visited.insert(n);
        q.push(n);
        int count = 0;

        while(!q.empty())
        {
            int size = q.size();
            
            for(int i = 0; i < size; i++)
            {
                int now = q.front();
                // cout << now << endl;
                q.pop();
                if(now == 0)
                    return count;

                for(int j = 1; j*j <= now; j++)
                {
                    if(now-j*j >= 0 && visited.find(now-j*j) == visited.end())
                    {
                        q.push(now-j*j);
                        visited.insert(now-j*j);
                    }
                }
            }
            count++;
            // cout << endl;
        }

        return 1;
    }
};

int main(){


    return 0;
}
