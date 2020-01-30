#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search2(nums, target);
    }

    int search1(vector<int>& nums, int target) {
        // 此方法是先找出中间的分割点
        // 然后选择左右块之一
        // 然后在其中二分查找
        // 需要两次循环，可改进

        if(nums.empty())    return -1;

        int i = 0;
        int j = nums.size() - 1;
        int midIndex = -1;

        while(i <= j){
            int mid = i + (j - i) / 2;

            if(mid != nums.size() - 1){
                if(nums[mid+1] < nums[mid]){
                    midIndex = mid;
                    break;
                }
            }else{
                midIndex = mid;
                break;
            }

            if(nums[mid] >= nums[i]){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }

        if(nums[midIndex] < target)
            return -1;

        if(nums[0] > target){
            i = midIndex + 1;
            j = nums.size() - 1;
        }
        else if(nums[0] == target){
            return 0;
        }
        else{
            i = 0;
            j = midIndex;
        }

        while(i <= j){
            int mid = i + (j - i) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                i = mid + 1;
            else
                j = mid - 1;
        }

        return -1;
    }

    int search2(vector<int>& nums, int target){
        // 循环内部判断是否单调自增

        if(nums.empty())    return -1;

        int i = 0;
        int j = nums.size() - 1;

        while(i <= j){
            int mid = i + (j - i) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[i] < nums[j]){
                if(nums[mid] < target)
                    i = mid + 1;
                else
                    j = mid - 1;
            }
            else{
                if(nums[mid] >= nums[i]){
                    if(target < nums[j])
                        i = mid + 1;
                    else if(target == nums[j])
                        return j;
                    else if(target < nums[i])
                        return -1;
                    else if(target == nums[i])
                        return i;
                    else if(target < nums[mid])
                        j = mid - 1;
                    else
                        i = mid + 1;
                }
                else{
                    if(target < nums[mid])
                        j = mid - 1;
                    else if(target < nums[j])
                        i = mid + 1;
                    else if(target == nums[j])
                        return j;
                    else if(target < nums[i])
                        return -1;
                    else if(target == nums[i])
                        return i;
                    else if(target > nums[i])
                        j = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main()
{

    vector<int> nums = {0,1,2,4,5,6,7,};
    Solution().search(nums, 0);

    return 0;
}