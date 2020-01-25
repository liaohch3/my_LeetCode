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
        return minSubArrayLen2(s, nums);
    }

    int minSubArrayLen1(int s, vector<int>& nums) {
        // 暴力法
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

    int minSubArrayLen2(int s, vector<int>& nums) {
        // 双指针

        int i = 0, j = 0, sum = 0, minLen = nums.size()+1;
        while(i < nums.size() && j <= nums.size())
        {
            while(sum < s && j < nums.size())
            {
                sum += nums[j];
                j++;
            }

            if(sum >= s && j - i < minLen)
                minLen = j - i;

            sum -= nums[i];
            i++;

            if(sum >= s && j - i < minLen)
                minLen = j - i;
        }

        return minLen <= nums.size() ? minLen : 0;
    }
};

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << Solution().minSubArrayLen(11, vec) << endl;
    return 0;
}