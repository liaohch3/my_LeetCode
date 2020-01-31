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
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int mid = -1;
        while(i <= j){
            mid = i + (j - i) / 2;
            if(nums[j] >= nums[i]){
                return nums[i];
            }else{
                if(nums[mid] >= nums[i])
                    i = mid + 1;
                else 
                    j = mid;
            }
        }

        return mid;
    }
};

int main()
{
    vector<int> nums = {4,5,6,7,8,-2,1,2,};
    cout << Solution().findMin(nums) << endl;

    return 0;
}