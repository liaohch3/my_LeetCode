/*
* @Author: liaohch3
* @Date:   2020-02-14 21:04:44
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 21:14:33
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)	return true;
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* root1, TreeNode* root2){
    	if(root1 == NULL && root2 == NULL)	return true;
    	if(root1 == NULL || root2 == NULL)	return false;

    	return (root1->val == root2->val) && 
    			helper(root1->left, root2->right) &&
    			helper(root1->right, root2->left);
    }
};

int main()
{
    
    return 0;
}