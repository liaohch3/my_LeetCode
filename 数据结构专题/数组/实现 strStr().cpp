#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)		return 0;
        if(haystack.size() == 0)	return -1;

        vector<int> prefix(needle.size(), 0);
        int prefixLen = 0;
        for(int i = 1; i < needle.size(); i++)
        {
        	if(needle[i] == needle[prefixLen])
        	{
        		prefixLen++;
        		prefix[i] = prefixLen;
        	}
        	else
        	{
        		if(prefixLen > 0)
	        		prefixLen = prefix[prefixLen - 1];
	        	else
	        		prefix[i] = 0;
        	}
        }


    }
};

int main()
{

	return 0;
}