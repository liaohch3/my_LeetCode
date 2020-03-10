/*
* @Author: liaohch3
* @Date:   2020-02-23 21:55:38
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-23 22:06:30
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
	vector<int> inorder;
	vector<int> postorder;
	// inorder值 => index
	unordered_map<int, int> hashMap;
	int post_idx;
public:

	// inorder 
	TreeNode* helper(int left, int right){
		if(left > right)
			return NULL;

		int target = postorder[post_idx]; // 3
		post_idx--;
		int in_idx = hashMap[target]; // 1
		
		TreeNode* now = new TreeNode(target);
		now->right = helper(in_idx+1, right);
		now->left = helper(left, in_idx-1);
		
		return now;
	}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	this->inorder = inorder;
    	this->postorder = postorder;
    	for(int i = 0; i < inorder.size(); i++){
    		hashMap[inorder[i]] = i;
    	}
    	post_idx = postorder.size() - 1;

    	return helper(0, inorder.size() - 1);
    }
};

int main()
{
    
    return 0;
}