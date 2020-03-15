/*
* @Author: liaohch3
* @Date:   2020-03-13 17:50:18
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-13 17:56:32
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

	int num;
    bool isUnivalTree(TreeNode* root) {
    	if(root == NULL)	return true;
    	num = root->val;
    	return helper(root);
    }

    bool helper(TreeNode* root){
    	if(root == NULL){
    		return true;
    	}
    	if(root->val != num){
    		return false;
    	}

    	return helper(root->left) && helper(root->right);
    }
};

int main()
{
    
    return 0;
}