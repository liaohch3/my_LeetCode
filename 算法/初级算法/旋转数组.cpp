/*
* @Author: liaohch3
* @Date:   2020-02-09 13:24:01
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-09 13:34:38
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

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1)	return;

        k %= nums.size();

        rotateLR(nums, nums.size() - k, nums.size()-1);
        rotateLR(nums, 0, nums.size() - k - 1);
        rotateLR(nums, 0, nums.size() - 1);
    }

    void rotateLR(vector<int>& nums, int l, int r){

    	int i = l;
    	int j = r;
    	while(i < j){
    		int temp = nums[i];
    		nums[i] = nums[j];
    		nums[j] = temp;

    		i++;
    		j--;
    	}
    }
};

int main()
{
	vector<int> nums = {1,2,3,4,5,6,7};
	int k = 3;
	Solution().rotate(nums, k);
	return 0;
}