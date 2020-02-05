/*
* @Author: liaohch3
* @Date:   2020-02-04 23:14:35
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-05 19:59:33
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        if(nums1.empty())   return findMedian(nums2);

        int len = m + n;
        int left = 0;
        int right = m; // 左闭右开

        int count1, count2;
        int l1, l2, r1, r2;
        while(left <= right){

            count1 = left + (right - left) / 2;
            count2 = len / 2 - count1;

            l1 = count1 == 0 ? INT_MIN : nums1[count1 - 1];
            l2 = count2 == 0 ? INT_MIN : nums2[count2 - 1];

            r1 = count1 == m ? INT_MAX : nums1[count1];
            r2 = count2 == n ? INT_MAX : nums2[count2];

            // cout << left << " " << right << " " << count1 << " " << count2 << " " << l1 
                 // << " " << l2 << " " << r1 << " " << r2 << " " << endl;

            if(l1 > r2){
                right = count1 - 1;
            }else if(l2 > r1){
                left = count1 + 1;
            }else{
                if(len % 2 == 0){
                    double l = l1 > l2 ? l1 : l2;
                    double r = r1 > r2 ? r2 : r1;
                    return (l + r) / 2;
                }else{
                    return r1 < r2 ? r1 : r2;
                }
            }
        }

        return -1;
    }

    double findMedian(vector<int>& nums){
        if(nums.size() % 2 == 1)
            return nums[nums.size() / 2];
        else
            return ((double)nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2;
    }
};

int main()
{

    vector<int> nums1 = {2, 4, 6, 8, 10, 12, 14};
    vector<int> nums2 = {1, 5, 8, 10, 11, 12, 12, 15};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {2, 4, 13, 14, 15, 16, 17};
    nums2 = {1, 5, 8, 10, 11, 12, 12, 15};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {};
    nums2 = {2, 3};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {};
    nums2 = {2, 3};
    cout << Solution().findMedianSortedArrays(nums2, nums1) << endl;

    return 0;
}