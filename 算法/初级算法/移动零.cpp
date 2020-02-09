/*
* @Author: liaohch3
* @Date:   2020-02-09 15:44:03
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-09 18:46:01
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
    void moveZeroes(vector<int>& nums) {
    	int i = 0;
    	int j = 0;
    	while(j < nums.size()){
    		if(nums[j] != 0){
    			nums[i] = nums[j];
    			i++;
    		}
    		j++;
    	}
    	while(i < nums.size()){
    		nums[i] = 0;
    		i++;
    	}
    }
};


int main()
{

	return 0;
}