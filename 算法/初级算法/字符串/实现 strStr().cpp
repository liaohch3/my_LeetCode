/*
* @Author: liaohch3
* @Date:   2020-02-14 15:33:04
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 15:41:08
*/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

class Solution {
public:

    vector<int> getPrefix(string needle){
        vector<int> prefix(needle.size(), 0);
        int prefixLen = 0;
        int i = 1;
        while(i < needle.size())
        {
            if(needle[i] == needle[prefixLen])
            {
                prefixLen++;
                prefix[i] = prefixLen;
                i++;
            } 
            else
            {
                if(prefixLen > 0)
                    prefixLen = prefix[prefixLen - 1];
                else
                {
                    prefix[i] = 0;
                    i++;
                }
            }
        }

        prefix.insert(prefix.begin(), 1, -1);
        prefix.pop_back();
        return prefix;
    }

    int strStr(string haystack, string needle) {
        if(needle.size() == 0)      return 0;
        if(haystack.size() == 0)    return -1;

        vector<int> prefix = getPrefix(needle);

        int i = 0;
        int j = 0;
        int m = haystack.size();
        int n = prefix.size();

        while(i < m)
        {
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = prefix[j];
                if(j == -1)
                {
                    j = 0;
                    i++;
                }
            }

            if(j == n)
                return i - j;
        }

        return -1;
    }
};

int main()
{
    
    return 0;
}