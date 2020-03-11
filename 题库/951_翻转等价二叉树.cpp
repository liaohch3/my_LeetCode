/*
* @Author: liaohch3
* @Date:   2020-03-11 23:51:07
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-12 00:13:57
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    	if(root1 == NULL) return root2 == NULL;
    	if(root2 == NULL) return root1 == NULL;

    	if(root1->val != root2->val)	return false;

    	return (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)) || (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right));
    }
};

int main()
{
    
    return 0;
}