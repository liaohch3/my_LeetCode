/*
* @Author: liaohch3
* @Date:   2020-02-04 22:03:32
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-04 22:14:30
*/
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet(nums1.begin(), nums1.end());
        unordered_set<int> resHashSet;
        vector<int> res;
        for(int item:nums2){
        	if(hashSet.count(item) == 1 && resHashSet.count(item) == 0){
        		res.push_back(item);
        		resHashSet.insert(item);
        	}
        }
        return res;
    }
};

int main()
{
	return 0;
}