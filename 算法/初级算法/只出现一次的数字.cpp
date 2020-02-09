/*
* @Author: liaohch3
* @Date:   2020-02-09 13:37:39
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-09 14:00:44
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
    int singleNumber(vector<int>& nums) {

    	// 要求：线性时间复杂度，常数空间复杂度
    	// 意味着不能排序，不能用哈希集合
    	// 突破点：异或

    	int num = 0;
    	for(int i = 0; i < nums.size(); i++)
    		num ^= nums[i];

    	return num;
    }
};

int main()
{

	return 0;
}