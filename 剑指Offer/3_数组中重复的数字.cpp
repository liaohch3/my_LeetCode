/*
* @Author: liaohch3
* @Date:   2020-02-18 18:33:51
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-18 18:42:00
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

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
        return findRepeatNumber2(nums);
    }

	void swap(int& a, int& b){
		int temp = a;
		a = b;
		b = temp;
	}

    int findRepeatNumber1(vector<int>& nums) {
    	// 最好的办法 桶思想
        for(int i = 0; i < nums.size(); i++){
        	while(nums[i] != i){
        		if(nums[nums[i]] == nums[i]){
        			return nums[i];
        		}
        		swap(nums[nums[i]], nums[i]);
        	}
        }
        return -1;
    }

	int findRepeatNumber2(vector<int>& nums) {
        // 哈希的思想
		vector<int> hashSet(nums.size(), 0);
		for(int item: nums){
			if(hashSet[item] == 0){
				hashSet[item]++;
			}else{
				return item;
			}
		}
		return -1;
    }
};

int main()
{
    
    return 0;
}