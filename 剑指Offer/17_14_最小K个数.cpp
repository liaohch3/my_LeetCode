/*
* @Author: liaohch3
* @Date:   2020-02-20 15:06:57
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-20 15:20:32
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
    vector<int> smallestK(vector<int>& arr, int k) {

        if(k == 0)
            return vector<int>();

    	if(arr.empty() || k >= arr.size())
    		return vector<int>(arr); 

        vector<int> heap(k, INT_MAX);
        for(int item: arr){
        	if(item < heap[0]){
        		heap[0] = item;
        		heapify(heap, 0, k);
        	}
        }

        return sortAfterHeapify(heap);
    }

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

    vector<int> sortAfterHeapify(vector<int>& nums) {
        // 堆排序

    	for(int i = nums.size() - 1; i >= 1; i--){
    		swap(nums[0], nums[i]);
    		heapify(nums, 0, i);
    	}

    	return vector<int>(nums);
    }
};

int main()
{
    // vector<int> nums = {-4,0,7,4,9,-5,-1,0,-7,-1};
    // vector<int> res = Solution().smallestK(nums, 4);
    // show(res);

    vector<int> nums = {1,3,5,7,2,4,6,8};
    vector<int> res = Solution().smallestK(nums, 4);
    show(res);
    return 0;
}