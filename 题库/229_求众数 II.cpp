/*
* @Author: liaohch3
* @Date:   2020-03-21 21:52:25
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-21 22:13:42
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

    	if(nums.size() <= 1){
    		return vector<int>(nums);
    	}
    	int num1 = nums[0], count1 = 0;
    	int num2 = nums[0], count2 = 0;

    	for(int item: nums){
    		if(item == num1){
    			count1++;
    			continue;
    		}
    		if(item == num2){
    			count2++;
    			continue;
    		}

    		if(count1 == 0){
    			num1 = item;
    			count1 = 1;
    			continue;
    		}
    		if(count2 == 0){
    			num2 = item;
    			count2 = 1;
    			continue;
    		}

    		count1--;
    		count2--;
    	}

    	count1 = 0;
    	count2 = 0;

    	for(int item: nums){
    		if(item == num1){
    			count1++;
    		}else if(item == num2){
    			count2++;
    		}
    	}

    	vector<int> res;
    	if(count1 > nums.size() / 3){
    		res.push_back(num1);
    	}
    	if(count2 > nums.size() / 3){
    		res.push_back(num2);
    	}

    	return res;
    }
};

int main()
{
	vector<int> nums = {1, 2};
    vector<int> res = Solution().majorityElement(nums);
    printf("%d %d\n", res[0], res[1]);
    return 0;
}