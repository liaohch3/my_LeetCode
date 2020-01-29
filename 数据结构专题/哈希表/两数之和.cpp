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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
        	if(hashMap.find(nums[i]) == hashMap.end()){
        		hashMap[target-nums[i]] = i;
        	}else{
        		vector<int> res(2);
        		res[0] = hashMap[nums[i]];
        		res[1] = i;
        		return res;
        	}
        } 

		vector<int> res(2);
		res[0] = 0;
		res[1] = 1;
		return res;
    }
};

int main()
{
	return 0;
}