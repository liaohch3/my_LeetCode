#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0; 
        int j = 0;
        while(i < nums.size() && j < nums.size())
        {
            if(nums[j] != 0)
            {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        while(i < nums.size())
        {
            nums[i] = 0;
            i++;
        }
    }
};

int main()
{

    return 0;
}