/*
* @Author: liaohch3
* @Date:   2020-02-20 14:45:04
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-20 15:04:24
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

	void swap(int& a, int& b){
		int temp = a;
		a = b;
		b = temp;
	}

	void heapify(vector<int>& nums, int index, int boundary){



		int maxIndex = index;

		int left = index * 2 + 1;
		if(left >= boundary)	return;
		if(nums[maxIndex] < nums[left]){
			maxIndex = left;
		}


		int right = index * 2 + 2;
		if(right < boundary){
			if(nums[maxIndex] < nums[right]){
				maxIndex = right;
			}
		}

		if(index != maxIndex){
			swap(nums[index], nums[maxIndex]);
			heapify(nums, maxIndex, boundary);
		}
	}

    vector<int> sortArray(vector<int>& nums) {
        // 堆排序
    	for(int i = (nums.size() - 2) / 2; i >= 0; i--){
			// cout << i << " && ";
    		heapify(nums, i, nums.size());
			// show(nums);
    	}


    	for(int i = nums.size() - 1; i >= 1; i--){
    		swap(nums[0], nums[i]);
    		heapify(nums, 0, i);
    	}

    	return vector<int>(nums);
    }
};

int main()
{
    vector<int> nums = {-4,0,7,4,9,-5,-1,0,-7,-1};
    vector<int> res = Solution().sortArray(nums);
    show(res);
    return 0;
}