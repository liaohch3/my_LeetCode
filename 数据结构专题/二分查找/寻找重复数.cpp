/*
* @Author: liaohch3
* @Date:   2020-02-04 22:34:56
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-04 23:14:01
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
    int findDuplicate(vector<int>& nums) {

        int i = 1;
        int j = nums.size() - 1;
        while(i < j){
            int mid = i + (j - i) / 2;
            int count = countIJ(nums, i, mid);
            if(count > mid - i + 1)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }

    int countIJ(vector<int>& nums, int left, int right){
        int count = 0;
        for(int item: nums)
            if(item >= left && item <= right)
                count++;
        return count;
    }
};

int main()
{
    std::vector<int> nums = {3,1,3,4,2};
    cout << Solution().findDuplicate(nums);
    return 0;
}