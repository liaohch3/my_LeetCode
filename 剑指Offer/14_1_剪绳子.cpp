/*
* @Author: liaohch3
* @Date:   2020-02-22 13:59:09
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-22 14:46:32
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
    int cuttingRope(int n) {
    	return cuttingRope2(n);
    }
    int cuttingRope1(int n) {
    	// 动态规划
    	vector<int> dp(n+1, 0);
    	dp[1] = 1;
    	dp[2] = 1;

    	for(int i = 3; i <= n; ++i){
    		int maxDp = i - 1;
    		for(int j = 2; j <= i / 2; ++j){
				maxDp = max(max(j, dp[j]) * max(i-j, dp[i-j]), maxDp);
    		}
    		dp[i] = maxDp;
    	}

    	return dp[n];
    }

    int cuttingRope2(int n){
    	// 特殊算法，贪心
    	// 所有数字最后都会被分解为1，2，3
    	// 对于大于等于5的数字优先分解成3
    	if(n < 4){
    		return n - 1;
    	}else{
    		long long res = 1;
    		while(n > 4){
    			res = (res * 3) % 1000000007;
    			n -= 3;
    		}
    		return (res * n) % 1000000007;
    	}
    }
};

int main()
{
    cout << Solution().cuttingRope(10);
    return 0;
}