#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a;
        unordered_set<int> b;
        vector<int> res;

        for(int i = 0; i < nums1.size(); i++)
        	a.insert(nums1[i]);
        // cout << a.size() << endl;
        for(int i = 0; i < nums2.size(); i++){
        	if(a.count(nums2[i]) == 1 && b.count(nums2[i]) == 0){
        		b.insert(nums2[i]);
        		res.push_back(nums2[i]);
        	}
        }
        // cout << b.size() << endl;
        return res;
    }
};

int main()
{
	return 0;
}