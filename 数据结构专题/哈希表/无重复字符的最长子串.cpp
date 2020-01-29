#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashMap;
        int maxLen = 0;
        int len = 0;
        int legel = -1;
        for(int i = 0; i < s.size(); i++){
        	if(hashMap.find(s[i]) == hashMap.end() || hashMap[s[i]] < legel){
        		len++;
        		maxLen = len > maxLen ? len : maxLen;
        		hashMap[s[i]] = i;
        	}
        	else{
        		len = i - hashMap[s[i]];
        		legel = hashMap[s[i]] + 1;
        		hashMap[s[i]] = i;
        	}
        }
        return maxLen;
    }
};

int main()
{
	cout << Solution().lengthOfLongestSubstring("pwwkew");

	return 0;
}