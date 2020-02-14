/*
* @Author: liaohch3
* @Date:   2020-02-14 21:15:09
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 21:20:01
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int> > res;
        if(root == NULL)	return res;
        q.push(root);
        while(!q.empty()){
        	int size = q.size();
        	vector<int> row(size);
        	for(int i = 0; i < size; i++){
        		TreeNode* now = q.front();
        		q.pop();
        		row[i] = now->val;
        		if(now->left){
        			q.push(now->left);
        		}
        		if(now->right){
        			q.push(now->right);
        		}
        	}
        	res.push_back(row);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}