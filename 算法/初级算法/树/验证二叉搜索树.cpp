/*
* @Author: liaohch3
* @Date:   2020-02-14 20:39:44
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 21:00:56
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
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;

        TreeNode* p = root;
        stack<TreeNode*> s;
        while(p){
            s.push(p);
            p = p->left;
        }

        long long num = (long long)INT_MIN - 1;

        while(!s.empty()){
            TreeNode* now = s.top();
            s.pop();
            if(now->val <= num){
                return false;
            }
            num = now->val;
            now = now->right;
            while(now){
                s.push(now);
                now = now->left;
            }
        }

        return true;
    }
};

int main()
{
    TreeNode* root = new TreeNode(2);
    TreeNode* p = root;
    p->left = new TreeNode(1);
    p->right = new TreeNode(3);
    // p = p->right;
    // p->left = new TreeNode(3);
    // p->right = new TreeNode(6);
    cout << Solution().isValidBST(root) << endl;
    return 0;
}