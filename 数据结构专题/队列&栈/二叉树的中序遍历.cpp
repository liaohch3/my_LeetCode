#include <iostream>
#include <stack>
#include <vector>
#include <queue>

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
    vector<int> inorderTraversal(TreeNode* root) {
        return inorderTraversalIteration(root);
    }

    vector<int> inorderTraversalRecursion(TreeNode* root) {
        // 递归法
        if(root == NULL)
            return vector<int>();
        
        if(root->left == NULL && root->right == NULL)
            return vector<int>(1, root->val);

        vector<int> left;
        if(root->left != NULL)
            left = inorderTraversal(root->left);
        vector<int> right;
        if(root->right != NULL)
            right = inorderTraversal(root->right);

        vector<int> res;
        res.insert(res.end(), left.begin(), left.end());
        res.push_back(root->val);
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }

    vector<int> inorderTraversalIteration(TreeNode* root) {
        // 迭代法

        if(root == NULL)
            return vector<int>();

        vector<int> res;
        stack<TreeNode*> s;

        while(root != NULL || !s.empty())
        {
            while(root != NULL)
            {
                s.push(root);
                root = root->left;
            }
            if(!s.empty())
            {
                TreeNode* p = s.top();
                s.pop();
                res.push_back(p->val);
                root = p->right;
            }
        }

        return res;

    }
};

int main()
{

    return 0;
}