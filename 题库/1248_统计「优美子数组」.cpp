/*
* @Author: liaohch3
* @Date:   2020-04-21 09:02:13
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-21 10:38:00
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

void show(vector<int>& v){
    for(int& item: v){
        cout << item << " ";
    }
    cout << endl;
}

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        if(nums.empty())    return 0;
        int n = nums.size();

        vector<int> q;
        q.push_back(-1);
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1){
                q.push_back(i);
            }
        }
        q.push_back(n);
        if(q.size() - 2 < k)    return 0;

        // show(q);

        int left = 1;
        int right = k;
        int i = q[left];
        int j = q[right];
        int res = 0;

        while(right < q.size() - 1){

            // printf("%d %d %d %d\n", q[left], q[left-1], q[right+1], q[right]);

            res += (q[left]-q[left-1]) * (q[right+1]-q[right]);
            left++;
            right++;
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    cout << Solution().numberOfSubarrays(nums, 2) << endl;

    nums = {1,1,2,1,1};
    cout << Solution().numberOfSubarrays(nums, 3) << endl;

    nums = {2,4,6};
    cout << Solution().numberOfSubarrays(nums, 1) << endl;
    return 0;
}