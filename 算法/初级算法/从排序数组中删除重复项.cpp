/*
* @Author: liaohch3
* @Date:   2020-02-09 11:38:08
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-09 11:59:38
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
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size() <= 1)	return nums.size();

    	int i = 0;
    	int j = 0;
    	while(j < nums.size()){
    		if(nums[j] == nums[i]){
    			j++;
    		}else{
    			i++;
    			nums[i] = nums[j];
    			j++;
    		}
    	}

    	return i+1;
    }
};


int main()
{
	vector<int> nums = {1, 1, 2};

	cout << Solution().removeDuplicates(nums) << endl;
	for(int item : nums){
		cout << item << " ";
	}
	return 0;
}