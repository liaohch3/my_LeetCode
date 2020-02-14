/*
* @Author: liaohch3
* @Date:   2020-02-14 21:21:02
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 21:47:06
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	TreeNode* helper(vector<int>& nums, int l, int r){
		if(l > r)	return NULL;
		int mid = l + (r - l) / 2;
		TreeNode* now = new TreeNode(nums[mid]);
		now->left = helper(nums, l, mid-1);
		now->right = helper(nums, mid+1, r);
		return now;
	}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())	return NULL;
        return helper(nums, 0, nums.size() - 1);
    }
};

int main()
{
    
    return 0;
}