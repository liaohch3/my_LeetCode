/*
* @Author: liaohch3
* @Date:   2020-04-04 11:17:04
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-04 11:37:41
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
    int trap(vector<int>& height) {
    	return trap2(height);
    }
    int trap2(vector<int>& height) {
    	// 双指针法
    	if(height.empty())	return 0;

    	int left = 0;
    	int right = height.size() - 1;
    	int res = 0;
    	int level = 0;
    	while(left < right){
    		// printf("left: %d, right: %d, height[left]: %d, height[right]: %d, level: %d, res: %d\n", left, right, height[left], height[right], level, res);
    		if(height[left] < height[right]){
    			level = max(level, height[left]);
    			res += max(0, level - height[left]);
    			left++;
    		}else{
    			level = max(level, height[right]);
    			res += max(0, level - height[right]);
    			right--;
    		}
    	}
    	return res;
    }
    int trap1(vector<int>& height) {
    	// 动态编程
    	if(height.empty())	return 0;

        vector<int> left(height.size());
        int maxLeft = 0;
        for(int i = 0; i < height.size(); i++){
        	maxLeft = max(maxLeft, height[i]);
        	left[i] = maxLeft;
        }

        vector<int> right(height.size());
        int maxRight = 0;
        for(int i = height.size() - 1; i >= 0; i--){
        	maxRight = max(maxRight, height[i]);
        	right[i] = maxRight;
        }

        int res = 0;
        for(int i = 0; i < height.size(); i++){
			res += min(left[i], right[i]) - height[i];
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution().trap(nums) << endl;
    return 0;
}