/*
* @Author: liaohch3
* @Date:   2020-02-04 23:14:35
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-04 23:19:08
*/
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }

    double findMedian(vector<int>& nums){
    	if(nums.size() % 2 == 1)
    		return nums[nums.size() / 2];
    	else
    		return (nums[nums.size() / 2 - 2] + nums[nums.size() / 2]) / 2;
    }
};

int main()
{
	return 0;
}