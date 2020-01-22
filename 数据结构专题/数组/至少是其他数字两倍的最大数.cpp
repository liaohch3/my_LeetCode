#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first = -1;
        int index = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > first)
            {
                first = nums[i];
                index = i;
            }
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(first < 2 * nums[i] && i != index)
                return -1;
        }
        return index;
    }
};

int main()
{

    return 0;
}