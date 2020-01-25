#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;
        while(i < nums.size())
        {
        	if(nums[i] != val)
        	{
        		nums[j] = nums[i];
        		j++;
        	}
        	i++;
        }
        return j;
    }
};

int main()
{

	return 0;
}