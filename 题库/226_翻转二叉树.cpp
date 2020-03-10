/*
* @Author: liaohch3
* @Date:   2020-02-23 22:07:19
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-23 22:10:06
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
    TreeNode* invertTree(TreeNode* root) {
    	if(root == NULL)	return NULL;

    	invertTree(root->left);
    	invertTree(root->right);

    	TreeNode* temp = root->left;
    	root->left = root->right;
    	root->right = temp;

    	return root;
    }
};

int main()
{
    
    return 0;
}