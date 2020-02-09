/*
* @Author: liaohch3
* @Date:   2020-02-09 14:00:56
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-09 14:04:33
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	unordered_map<int, int> hashMap;
    	for(int item: nums1)
    		hashMap[item]++;

    	vector<int> res;
    	for(int item: nums2){
    		if(hashMap[item] > 0){
    			hashMap[item]--;
    			res.push_back(item);
    		}
    	}

    	return res;
    }
};

int main()
{

	return 0;
}