#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        rotate2(nums, k);
    }

    void rotate1(vector<int>& nums, int k) {
        // 暴力法 无法通过
        if(nums.size() <= 1 || k % nums.size() == 0)    return;

        k = k % nums.size();

        for(int j = 0; j < k; j++)
        {
            int back = nums.back();
            for(int i = nums.size() - 2; i >= 0; i--)
                nums[i+1] = nums[i];
            nums[0] = back;
        }
    }

    void reverse(vector<int>& nums, int left, int right)
    {
        int i = left;
        int j = right;
        while(i < j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }

    void rotate2(vector<int>& nums, int k) {
        // 三次反转 强强强！
        if(nums.size() <= 1 || k % nums.size() == 0)    return;

        k = k % nums.size();

        reverse(nums, nums.size()-k, nums.size()-1);

        reverse(nums, 0, nums.size()-k-1);

        reverse(nums, 0, nums.size()-1);
    }

};

int main()
{
    vector<int> nums = {1, 2};
    Solution().rotate(nums, 1);
    for(int i = 0; i < nums.size(); i++
        cout << nums[i] << endl;)
    return 0;
}