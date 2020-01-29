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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        int maxDist = -1;
        for(int i = 0; i < nums.size(); i++){
        	if(hashMap.find(nums[i]) == hashMap.end())
        		hashMap[nums[i]] = i;
        	else if(i - hashMap[nums[i]] > maxDist)
        		maxDist = i - hashMap[nums[i]];
        }

        return maxDist == k;
    }
};

int main()
{
	return 0;
}