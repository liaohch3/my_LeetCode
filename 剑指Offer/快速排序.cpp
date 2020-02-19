/*
* @Author: liaohch3
* @Date:   2020-02-19 15:18:46
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-19 15:57:21
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

void show(const vector<int>& nums){
	for(int item: nums){
		cout << item << " ";
	}
	cout << endl;
}

class Solution {
public:

	int partition(vector<int>& nums, int left, int right){
		if(left <= right){
			int pivot = nums[left];
			int i = left;
			int j = right;
			while(i < j){
				while(i < j && nums[j] >= pivot) j--;
				nums[i] = nums[j];

				while(i < j && nums[i] <= pivot) i++;
				nums[j] = nums[i];
			}

			nums[i] = pivot;
			return i;
		}else{
			return -1;
		}
	}

	void helper(vector<int>& nums, int left, int right){
		if(left <= right){
			int par = partition(nums, left, right);
			helper(nums, left, par - 1);
			helper(nums, par + 1, right);
		}
	}

    vector<int> sortArray(vector<int>& nums) {
        // 快速排序
    	helper(nums, 0, nums.size() - 1);
    	return vector<int>(nums);
    }
};

int main()
{
    vector<int> nums = {2,8,5,2,3,1};
    vector<int> res = Solution().sortArray(nums);
    show(res);
    return 0;
}