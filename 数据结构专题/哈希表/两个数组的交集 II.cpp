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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashMap1;
        unordered_map<int, int> hashMap2;
        for(int i = 0; i < nums1.size(); i++){
        	if(hashMap1.find(nums1[i]) == hashMap1.end())
        		hashMap1[nums1[i]] = 1;
        	else
        		hashMap1[nums1[i]]++;
        }

        vector<int> res;

        for(int i = 0; i < nums2.size(); i++){
        	if(hashMap1.find(nums2[i]) != hashMap1.end()){
        		hashMap1[nums2[i]]--;
        		res.push_back(nums2[i]);
        		if(hashMap1[nums2[i]] == 0)
        			hashMap1.erase(nums2[i]);
        	}
        }

        return res;
    }
};

int main()
{
	return 0;
}