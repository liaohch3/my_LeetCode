#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int minLen = nums.size()+1;

        for(int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for(int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if(sum >= s)
                {
                    if(j-i+1<minLen)
                    {
                        minLen = j-i+1;
                    }
                    break;
                }
            }
            if(sum < s)
                break;
        }

        if(minLen <= nums.size())
            return minLen;
        return 0;
    }
};

int main()
{

    return 0;
}