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

        nums.insert(nums.begin(), 1, -0x7fffffff);
        nums.insert(nums.end(), 1, -0x7fffffff);


        int i = 1;
        int j = nums.size() - 2;

        while(i <= j){
        	int mid = i + (j - i) / 2;
        	if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1])
        		return mid - 1; 

        	else if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1])
        		i = mid + 1;

        	else
        		j = mid - 1;
        }

        nums.erase(nums.begin());
        nums.erase(nums.end());

        return 1;
    }
};

int main()
{

	// vector<int> nums = {1,2,3,1};
	vector<int> nums = {1,2,1,3,5,6,4};

	cout << Solution().findPeakElement(nums) << endl;

	return 0;
}