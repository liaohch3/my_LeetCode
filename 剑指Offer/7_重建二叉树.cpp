/*
* @Author: liaohch3
* @Date:   2020-02-19 11:12:32
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-19 11:27:38
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


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<int> preorder;
	vector<int> inorder;
	int pre_idx;
	unordered_map<int, int> hashMap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    	if(preorder.empty())	return NULL;

        this->preorder = preorder;
        this->inorder = inorder;
        this->pre_idx = 0;

        for(int i = 0; i < inorder.size(); i++){
        	this->hashMap[inorder[i]] = i;
        }

        return helper(0, inorder.size() - 1);
    }

    TreeNode* helper(int left, int right) {

    	if(left > right)	return NULL;

    	int now = preorder[pre_idx];
        TreeNode* res = new TreeNode(now);
        pre_idx++;

        int tar_idx = hashMap[now];
        res->left = helper(left, tar_idx-1);
        res->right = helper(tar_idx+1, right);

        return res;
    }
};

void show(TreeNode* res){
	if(res == NULL)	return;
	cout << res->val << " ";
	show(res->left);
	show(res->right);
}

int main()
{
    std::vector<int> preorder = {3,9,20,15,7};
    std::vector<int> inorder = {9,3,15,20,7};
    TreeNode* res = Solution().buildTree(preorder, inorder);
    show(res);
    return 0;
}