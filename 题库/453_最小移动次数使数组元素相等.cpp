/*
* @Author: liaohch3
* @Date:   2020-03-10 15:36:34
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-10 15:39:57
*/

#include <iostream>
#include <stack>
#include <string>
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
    int minMoves(vector<int>& nums) {
    	int minValue = nums[0];
    	for(int i = 0; i < nums.size(); i++){
    		if(nums[i] < minValue){
    			minValue = nums[i];
    		}
    	}

    	int res = 0;
    	for(int i = 0; i < nums.size(); i++){
    		res += nums[i] - minValue;
    	}
    	return res;
    }
};

int main()
{
    std::vector<int> v = {1,2,3};
    cout << Solution().minMoves(v);
    return 0;
}