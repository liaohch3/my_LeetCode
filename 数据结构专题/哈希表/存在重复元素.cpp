#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int i = 0; i < nums.size(); i++){
        	if(hashSet.count(nums[i]) > 0)
        		return true;
        	hashSet.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
	return 0;
}