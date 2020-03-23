/*
* @Author: liaohch3
* @Date:   2020-03-23 11:34:09
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-23 11:42:32
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
    bool isStraight(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int gui = 0;
    	for(int i = 0; i < 5; i++){
    		if(nums[i] == 0){
    			gui++;
    		}else{
    			break;
    		}
    	}

    	for(int i = gui+1; i < 5; i++){
    		if(nums[i] != nums[i-1] + 1){
    			if(gui){
    				nums[i-1]++;
    				gui--;
    				i--;
    			}else{
    				return false;
    			}
    		}
    	}

    	return true;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4,5};
    cout << Solution().isStraight(nums) << endl;
    nums = {0,0,1,2,5};
    cout << Solution().isStraight(nums) << endl;
    nums = {9,0,6,0,10};
    cout << Solution().isStraight(nums) << endl;
    nums = {1,2,3,4,5};
    cout << Solution().isStraight(nums) << endl;
    return 0;
}