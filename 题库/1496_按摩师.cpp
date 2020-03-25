/*
* @Author: liaohch3
* @Date:   2020-03-24 11:14:20
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-24 11:35:20
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

class Solution {

	unordered_map<int, int> hashMap;

	int helper(vector<int>& nums, int index){
		if(index >= nums.size())	return 0;
		if(hashMap.find(index) != hashMap.end())	return hashMap[index];

		int res = max(helper(nums, index+1), helper(nums, index+2) + nums[index]);
		hashMap[index] = res;
		return res;
	}

	int dpFunc(vector<int>& nums){
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for(int i = 2; i < nums.size(); i++){
			dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
		}
		return dp.back();
	}

public:

    int massage(vector<int>& nums) {
    	if(nums.empty())		return 0;
    	if(nums.size() == 1)	return nums[0];
    	// return helper(nums, 0);
    	return dpFunc(nums);
    }
};

int main()
{
    vector<int> nums = {1,2,3,1};
    cout << Solution().massage(nums) << endl;
    nums = {2,7,9,3,1};
    cout << Solution().massage(nums) << endl;
    nums = {2,1,4,5,3,1,1,3};
    cout << Solution().massage(nums) << endl;
    return 0;
}