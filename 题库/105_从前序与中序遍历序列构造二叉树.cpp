/*
* @Author: liaohch3
* @Date:   2020-03-16 14:22:32
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-16 14:28:16
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

	vector<int> preorder;
	vector<int> inorder;
	int preIdx;
	unordered_map<int, int> hashMap;

	TreeNode* helper(int l, int r){

		if(l > r)	return NULL;

		int val = preorder[preIdx];
		preIdx++;

		TreeNode* root = new TreeNode(val);
		int mid = hashMap[val];

		root->left = helper(l, mid-1);
		root->right = helper(mid+1, r);

		return root;
	}

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	this->preorder = preorder;
		this->inorder = inorder;
		preIdx = 0;

		for(int i = 0; i < inorder.size(); i++){
			hashMap[inorder[i]] = i;
		}

		return helper(0, inorder.size() - 1);
    }
};

int main()
{
    
    return 0;
}