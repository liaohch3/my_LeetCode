/*
* @Author: liaohch3
* @Date:   2020-03-16 14:30:10
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-16 15:07:37
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
	unordered_map<int, int> hashMap;
	vector<int> pre;
	vector<int> post;
	int preIdx;

	TreeNode* helper(int l, int r){

		if(l > r)	return NULL;
		if(l == r){
			return new TreeNode(pre[preIdx++]);
		}

		TreeNode* root = new TreeNode(pre[preIdx]);
		int position = hashMap[pre[preIdx+1]];
		preIdx++;
		
		root->left = helper(l, position);
		root->right = helper(position+1, r-1);

		return root;
	}

public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    	this->pre = pre;
    	this->post = post;
    	preIdx = 0;

		for(int i = 0; i < post.size(); i++){
			hashMap[post[i]] = i;
		}

		return helper(0, post.size() - 1);
    }
};

int main()
{
    
    return 0;
}