/*
* @Author: liaohch3
* @Date:   2020-03-16 15:07:50
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-16 15:21:16
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

	void quick_sort(vector<int>& nums, int left, int right){
		if(left > right)	return;
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
		quick_sort(nums, left, i-1);
		quick_sort(nums, i+1, right);
	}

public:
    vector<int> sortArray(vector<int>& nums) {
    	vector<int> res(nums);
    	quick_sort(res, 0, nums.size() - 1);
    	return res;
    }
};

int main()
{
    vector<int> nums = {5,1,1,2,0,0};
    vector<int> res = Solution().sortArray(nums);
    for(int item: res){
    	cout << item << endl;
    }
    return 0;
}