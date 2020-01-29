#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

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