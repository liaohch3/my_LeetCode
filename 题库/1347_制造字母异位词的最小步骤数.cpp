/*
* @Author: liaohch3
* @Date:   2020-03-14 14:30:14
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-14 14:32:46
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
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
    int minSteps(string s, string t) {
    	int a[26] = {0};
    	for(char ch: s){
    		a[ch-'a']++;
    	}
    	int b[26] = {0};
    	for(char ch: t){
    		b[ch-'a']++;
    	}
    	int res = 0;
    	for(int i = 0; i < 26; i++){
    		if(b[i] > a[i]){
    			res += b[i] - a[i];
    		}
    	}
    	return res;
    }
};

int main()
{
    cout << Solution().minSteps("bab", "aba") << endl;
    cout << Solution().minSteps("leetcode", "practice") << endl;
    cout << Solution().minSteps("anagram", "mangaar") << endl;
    cout << Solution().minSteps("xxyyzz", "xxyyzz") << endl;
    cout << Solution().minSteps("friend", "family") << endl;
    return 0;
}