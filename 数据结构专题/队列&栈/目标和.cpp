#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。
现在你有两个符号 + 和 -。对于数组中的任意一个整数，
你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
*/

class Solution {
public:
    // DFS
    map<pair<int, long long>, int> m;

    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWaysIndex(nums, 0, S);
    }

    int findTargetSumWaysIndex(vector<int>& nums, int index, long long S) {
        if(index == nums.size() - 1)
            return (nums.back() == S) + (nums.back() == -S);

        if(m.find(make_pair(index, S)) != m.end())
            return m[make_pair(index, S)];

        if(nums[index] == 0)
        {
            int temp = 2 * findTargetSumWaysIndex(nums, index+1, S);
            m[make_pair(index+1, S)] = temp;
            return temp;
        }

        int a = findTargetSumWaysIndex(nums, index+1, S-nums[index]);
        m[make_pair(index+1, S-nums[index])] = a;
        int b = findTargetSumWaysIndex(nums, index+1, S+nums[index]);
        m[make_pair(index+1, S+nums[index])] = b;

        return a + b;
    }
};

int main()
{


    return 0;
}