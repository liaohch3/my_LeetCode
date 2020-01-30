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
        if(nums.empty())
            return -1;

        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){
            // int mid = (i + j) / 2; 避免 i + j 溢出
            int mid = i + (i - j) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return -1;
    }
};

int main()
{
    return 0;
}