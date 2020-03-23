/*
* @Author: liaohch3
* @Date:   2020-03-23 15:47:59
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-23 16:08:19
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
    vector<int> searchRange(vector<int>& nums, int target) {
    	if(nums.empty())	return vector<int>(2, -1);

        int i = 0; 
        int j = nums.size() - 1;
        while(i < j){
        	int mid = i + (j - i) / 2;
        	if(nums[mid] == target){
        		i = mid;
        		j = mid;
        		break;
        	}else if(nums[mid] < target){
        		i = mid + 1;
        	}else{
        		j = mid - 1;
        	}
        }

        // cout << i << j << endl;

        if(nums[i] != target)	return vector<int>(2, -1);

        vector<int> res(2, i);

        int m = 0;
        while(i - m - 1 >= 0 && nums[i-m-1] == target){
        	m++;
        }
        int n = 0;
        while(i + n + 1 < nums.size() && nums[i+n+1] == target){
        	n++;
        }
        
        res[0] = i - m;
        res[1] = i + n;
        return res;
    }
};

int main()
{
    vector<int> v = {1};
    vector<int> res = Solution().searchRange(v, 1);
    printf("%d %d\n", res[0], res[1]);

    v = {1,2,3};
    res = Solution().searchRange(v, 2);
    printf("%d %d\n", res[0], res[1]);
    return 0;
}