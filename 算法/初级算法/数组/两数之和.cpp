/*
* @Author: liaohch3
* @Date:   2020-02-12 14:16:41
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-12 15:19:55
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
    vector<int> twoSum(vector<int>& nums, int target) {
    	unordered_map<int, int> hashMap;
    	vector<int> res(2, 0);
    	for(int i = 0; i < nums.size(); i++){
    		if(hashMap.find(nums[i]) == hashMap.end()){
    			hashMap[target-nums[i]] = i;
    		}else{
    			res[0] = hashMap[nums[i]];
    			res[1] = i;
    		}
    	}
    	return res;
    }
};

int main()
{
    
    return 0;
}