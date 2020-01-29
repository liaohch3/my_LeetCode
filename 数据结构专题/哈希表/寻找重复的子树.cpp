#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

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

	string func(TreeNode* root, unordered_map<string, int>& hashMap, vector<TreeNode*>& res){
		if(root == NULL)	return "#";

		string now = to_string(root->val) + "," + func(root->left, hashMap, res) + "," + func(root->right, hashMap, res);
		if(hashMap.find(now) == hashMap.end())	
			hashMap[now] = 0;
		else if(hashMap[now] == 1)
			res.push_back(root);

		hashMap[now] ++;

		return now;
	}

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // 用一个前序遍历的字符串来表示一棵子树

        unordered_map<string, int> hashMap;
        vector<TreeNode*> res;
        func(root, hashMap, res); 
    	return res;
    }
};

int main()
{
	return 0;
}