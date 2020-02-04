/*
* @Author: liaohch3
* @Date:   2020-02-04 21:31:58
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-04 21:52:45
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
        return findMin2(nums);    
    }

    int findMin1(vector<int>& nums) {
        // 垃圾版本

        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){
            while(i <= j && i != nums.size() - 1 && nums[i+1] == nums[i])
                i++;
            if(i > j || i == nums.size() - 1)   
                break;
            while(i <= j && j != 0 && nums[j-1] == nums[j])
                j--;
            if(i > j || j == 0) 
                break;

            int mid = i + (j - i) / 2;
            if(i == j || nums[i] < nums[j]){
                return nums[i];
            }
            else{
                if(nums[mid] >= nums[i]){
                    i = mid + 1;
                }
                else{
                    j = mid;
                }
            }
        }
        return nums[i];
    }

    int findMin2(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            if(nums[i] < nums[j])
                return nums[i];

            int mid = i + (j - i) / 2;
            if(nums[mid] > nums[i])
                i = mid + 1;
            else if(nums[mid] == nums[i])
                i++;
            else
                j = mid;
        } 
        return nums[i];
    }
};

int main()
{

    std::vector<int> nums = {2,2,2,0,1};
    cout << Solution().findMin(nums) << endl;

    return 0;
}