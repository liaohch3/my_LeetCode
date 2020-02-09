/*
* @Author: liaohch3
* @Date:   2020-02-09 13:35:37
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-09 13:36:46
*/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	unordered_set<int> hashSet;
    	for(int item: nums){
    		if(hashSet.count(item) == 1)
    			return true;
    		hashSet.insert(item);
    	}
    	return false;
    }
};


int main()
{

	return 0;
}