/*
* @Author: liaohch3
* @Date:   2020-03-13 17:29:51
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-13 17:47:28
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
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
    int majorityElement(vector<int>& nums) {
    	int n = nums.size();

    	if(n == 1)	return nums[0];
    	unordered_map<int, int> hashMap;
    	for(int num: nums){
    		hashMap[num]++;
    		if(hashMap[num] > n / 2){
    			return num;
    		}
    	}
    	
        return nums[0];
    }
};

int main()
{
    
    return 0;
}