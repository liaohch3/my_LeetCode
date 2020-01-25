#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    	if(nums.empty())	return 0;

        int first = -1;
        int maxLen = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
        	if(nums[i] == 0)
        	{
        		if(i - first - 1 > maxLen)
        			maxLen = i - first - 1;
        		first = i;
        	}
        }
        if(nums.size() - first - 1 > maxLen)
        	maxLen = nums.size() - first - 1;
        return maxLen;
    }
};

int main()
{

	return 0;
}