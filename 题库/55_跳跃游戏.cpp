/*
* @Author: liaohch3
* @Date:   2020-04-17 11:19:10
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-17 11:34:55
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
    bool canJump(vector<int>& nums) {
        int now = 0;
        for(int i = 0; i < nums.size(); i++){
            if(now < i){
                return false;
            }
            now = max(i+nums[i], now);
        }
        return true;
    }
};

int main()
{
    
    return 0;
}