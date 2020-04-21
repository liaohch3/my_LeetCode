/*
* @Author: liaohch3
* @Date:   2020-04-18 08:07:43
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-18 08:13:50
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
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int res = 0;
        while(i < j){
        	if(height[i] < height[j]){
        		res = max(height[i] * (j - i), res);
        		i++;
        	}else{
        		res = max(height[j] * (j - i), res);
        		j--;
        	}
        }
        return res;
    }
};

int main()
{
	vector<int> nums = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(nums) << endl;
    return 0;
}