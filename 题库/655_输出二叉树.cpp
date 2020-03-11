/*
* @Author: liaohch3
* @Date:   2020-03-12 00:14:06
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-12 00:39:14
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
    vector<vector<string> > printTree(TreeNode* root) {
    	if(!root)	return vector<vector<string> >();
    	int height = getHeight(root);
    	cout << height << endl;
    	int n = myPow(height) - 1;
    	cout << n << endl;
    	vector<vector<string> > res(height, vector<string>(n, ""));

    	helper(res, root, 0, n / 2, n);
    	return res;
    }

    void helper(vector<vector<string> >& res, TreeNode* root, int x, int y, int n){
    	if(!root){
    		return;
    	}

		res[x][y] = to_string(root->val);
    	helper(res, root->left, x+1, y - (n+1)/myPow(2+x), n);
    	helper(res, root->right, x+1, y + (n+1)/myPow(2+x), n);
    }

    int getHeight(TreeNode* root){
    	if(root == NULL)	return 0;
    	return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    int myPow(int n){
    	int res = 1;
    	for(int i = 0; i < n; i++){
    		res *= 2;
    	}
    	return res;
    }
};

int main()
{
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(5);
    p->left->left = new TreeNode(3);
    p->left->left->left = new TreeNode(4);
    vector<vector<string> > res = Solution().printTree(p);

    for(int i = 0; i < res.size(); i++){
    	for(int j = 0; j < res[0].size(); j++){
    		if(res[i][j] == ""){
    			cout << '_' << " ";
    		}else{
    			cout << res[i][j] << " ";
    		}
    	}
    	cout << endl;
    }
    return 0;
}