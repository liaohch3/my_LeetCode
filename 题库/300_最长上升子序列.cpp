/*
* @Author: liaohch3
* @Date:   2020-03-14 10:32:12
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-14 12:33:58
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
    int lengthOfLIS(vector<int>& nums) {
    	return lengthOfLIS2(nums);
    }

    int lengthOfLIS1(vector<int>& nums) {
    	if(nums.size() <= 1)	return nums.size();

    	int maxOne = 1;
    	vector<int> dp(nums.size(), 1);
    	for(int i = 0; i < nums.size(); i++){
    		for(int j = 0; j < i; j++){
    			if(nums[i] > nums[j]){
    				dp[i] = max(dp[i], dp[j]+1);
    			}
    		}
    		maxOne = max(maxOne, dp[i]);
    	}

    	return maxOne;
    }
    int lengthOfLIS2(vector<int>& nums) {
    	if(nums.size() <= 1)	return nums.size();

    	int len = 1;
    	vector<int> dp(nums.size(), nums[0]);

    	for(int i = 1; i < nums.size(); i++){
    		
    		// cout << nums[i] << " ";
    		// for(int k = 0; k < len; k++){
    		// 	cout << dp[k] << " ";
    		// }
    		// cout << endl;
    		if(nums[i] > dp[len-1]){
    			dp[len] = nums[i];
    			len++;
    		}else{
    			int m = 0;
    			int n = len - 1;
    			while(m < n){
    				int mid = m + (n - m) / 2;
    				// printf("%d %d %d\n", m, n, mid);
					if(dp[mid] < nums[i]){
    					m = mid + 1;
    				}else {
    					n = mid;
    				}
    			}
    			dp[m] = nums[i];
    		}
    	}

    	return len;
    }
};

int main()
{
    vector<int> nums = {2, 2};
    cout << Solution().lengthOfLIS(nums) << endl;

    return 0;
}