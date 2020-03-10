/*
* @Author: liaohch3
* @Date:   2020-03-10 14:54:52
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-10 15:23:30
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	int globalLength;

	Solution():globalLength(0){}
    int diameterOfBinaryTree(TreeNode* root) {
    	int maxHeight = helper(root);
    	return max(maxHeight, globalLength);
    }

	int helper(TreeNode* root) {

    	if(root == NULL)	return 0;
    	if(root->left == NULL && root->right == NULL)	return 0;

    	int leftHeight = 0;
    	if(root->left){
    		leftHeight = 1 + helper(root->left);
    	}
    	int rightHeight = 0;
    	if(root->right){
    		rightHeight = 1 + helper(root->right);
    	}
    	
    	globalLength = max(globalLength, leftHeight + rightHeight);

    	return max(leftHeight, rightHeight);
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* p = root;
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    // p->left->right = new TreeNode(5);
    cout << Solution().diameterOfBinaryTree(root) << endl;
    return 0;
}