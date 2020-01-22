#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        if(nums.empty())        return -1;
        if(nums.size() == 1)    return 0;

        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];

        int left = 0;
        int right = sum;

        for(int i = 0; i < nums.size(); i++)
        {
            right -= nums[i];
            if(left == right)
                return i;

            left += nums[i];
        }

        return -1;
    }
};

int main()
{

    return 0;
}