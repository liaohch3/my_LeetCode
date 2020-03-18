/*
* @Author: liaohch3
* @Date:   2020-03-16 15:32:21
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-16 15:50:05
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
    int longestCommonSubsequence(string text1, string text2) {
    	if(text1.empty() || text2.empty())	return 0;

    	int m = text1.size();
    	int n = text2.size();
    	vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

    	for(int i = 1; i <= m; i++){
    		for(int j = 1; j <= n; j++){
    			if(text1[i-1] == text2[j-1]){
    				dp[i][j] = dp[i-1][j-1] + 1;
    			}else{
    				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    			}
    		}
    	}

    	return dp[m][n];
    }
};

int main()
{
    // cout << Solution().longestCommonSubsequence("abcde", "ace") << endl;
    // cout << Solution().longestCommonSubsequence("abc", "abc") << endl;
    // cout << Solution().longestCommonSubsequence("abc", "def") << endl;
    cout << Solution().longestCommonSubsequence("bsbininm", "jmjkbkjkv") << endl;
    return 0;
}