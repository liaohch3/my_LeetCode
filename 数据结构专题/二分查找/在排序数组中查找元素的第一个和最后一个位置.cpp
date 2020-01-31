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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty())    
            return res;

        res[0] = findFirst(nums, target);
        res[1] = findLast(nums, target);
        
        return res;
    }

    int findFirst(vector<int>& nums, int target){
        int i = 0;
        int j = nums.size() - 1;
        int res = -1;
        while(i <= j){
            int mid = i + (j - i) / 2;

            if(nums[mid] == target)
                res = mid;

            if(nums[mid] >= target)
                j = mid - 1;
            else 
                i = mid + 1;
        }

        return res;
    }

    int findLast(vector<int>& nums, int target){
        int i = 0;
        int j = nums.size() - 1;
        int res = -1;
        while(i <= j){
            int mid = i + (j - i) / 2;

            if(nums[mid] == target)
                res = mid;

            if(nums[mid] <= target)
                i = mid + 1;
            else 
                j = mid - 1;
        }

        return res;
    }

};

int main()
{
    return 0;
}