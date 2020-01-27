#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)    return nums.size();

        int now = nums[0];
        int i = 0;
        int j = 0;
        while(i < nums.size() && j < nums.size())
        {
            while(j < nums.size() && now == nums[j])
                j++;

            if(i+1 < nums.size() && j < nums.size())
            {
                nums[i+1] = nums[j];
                now = nums[j];
                i++;
                if(j == nums.size() - 1)
                    break;
            }
        }
        return i+1;
    }
};

int main()
{
    vector<int> nums = {1, 1};
    // vector<int> nums = {1, 1, 2};
    // vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << Solution().removeDuplicates(nums) << endl;
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}