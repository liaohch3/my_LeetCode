/*
* @Author: liaohch3
* @Date:   2020-02-14 21:47:46
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 21:53:15
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
#include <time.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m+n);
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < m && j < n){
        	if(nums1[i] < nums2[j]){
        		res[k] = nums1[i];
        		i++;
        	}else{
        		res[k] = nums2[j];
        		j++;
        	}
        	k++;
        }
        while(i < m){
			res[k] = nums1[i];
			i++;
			k++;
        }
        while(j < n){
			res[k] = nums2[j];
			j++;
			k++;
        }
        for(int i = 0; i < m+n; i++)
        	nums1[i] = res[i];
    }
};


int main()
{
    
    return 0;
}