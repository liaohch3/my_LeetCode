#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)    return "";
        if(strs.size() == 0)    return strs[0];

        int minLen = strs[0].size();
        int index = 0;

        for(int i = 0; i < strs.size(); i++)
        {
            if(strs[i].size() < minLen)
            {
                minLen = strs[i].size();
                index = i;
            }
        }

        string prefix = "";
        for(int k = 0; k < minLen; k++)
        {
            bool flag = true;
            char ch = strs[index][k];
            for(int i = 0; i < strs.size(); i++)
            {
                if(strs[i][k] != ch)
                    flag = false;
            }
            if(flag)
                prefix += ch;
            else
                break;
        }
        return prefix;
    }
};

int main()
{

    return 0;
}