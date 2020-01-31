#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int i = 0;
        int j = nums.size() - 1;

        while(i <= j){
        	int mid = i + (j - i) / 2;
        	if((mid == 0 || nums[mid] > nums[mid-1]) && (mid == nums.size() - 1 || nums[mid] > nums[mid+1]))
        		return mid; 

        	else if(mid != 0 && nums[mid] < nums[mid-1])
        		j = mid - 1;
        	else
        		i = mid + 1;
        }

        return 1;
    }
};

int main()
{
-2147483648
	// vector<int> nums = {1,2,3,1};
	vector<int> nums = {1,2,1,3,5,6,4};

	cout << Solution().findPeakElement(nums) << endl;

	return 0;
}