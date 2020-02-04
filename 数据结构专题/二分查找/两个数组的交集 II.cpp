/*
* @Author: liaohch3
* @Date:   2020-02-04 22:14:08
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-04 22:15:07
*/
/*
* @Author: liaohch3
* @Date:   2020-02-04 22:03:32
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-04 22:12:52
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashMap;
        for(int item: nums1){
            hashMap[item]++;
        }
        vector<int> res;
        for(int item:nums2){
            if(hashMap[item] > 0){
                res.push_back(item);
                hashMap[item]--;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}