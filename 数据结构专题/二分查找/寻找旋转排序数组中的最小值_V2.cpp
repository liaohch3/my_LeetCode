/*
* @Author: liaohch3
* @Date:   2020-02-04 21:22:56
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-04 21:32:57
*/
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){
            int mid = i + (j - i) / 2;
            if(nums[i] <= nums[j]){
                return nums[i];
            }else{
                if(nums[mid] >= nums[i]){
                    i = mid + 1;
                }
                else{
                    j = mid;
                }
            }
        }
        return i;
    }
};

int main()
{
    return 0;
}