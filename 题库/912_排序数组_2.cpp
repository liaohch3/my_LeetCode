/*
* @Author: liaohch3
* @Date:   2020-03-31 10:38:09
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-31 10:44:43
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

	void quictSort(vector<int>& nums, int left, int right){
		if(left <= right){
			int pivot = nums[left];
			int i = left;
			int j = right;

			while(i < j){
				while(i < j && nums[j] >= pivot)	j--;
				nums[i] = nums[j];
				while(i < j && nums[i] <= pivot)	i++;
				nums[j] = nums[i];
			}

			nums[i] = pivot;
			quictSort(nums, left, i-1);
			quictSort(nums, i+1, right);
		}
	}

public:
    vector<int> sortArray(vector<int>& nums) {
    	vector<int> res(nums);
    	quictSort(res, 0, nums.size() - 1);
    	return res;
    }
};

int main()
{
    vector<int> nums = {5,2,4,6,8,1};
    vector<int> res = Solution().sortArray(nums);
    for(int& item: res){
    	cout << item << endl;
    }
    return 0;
}