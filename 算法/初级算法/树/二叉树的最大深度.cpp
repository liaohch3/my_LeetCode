/*
* @Author: liaohch3
* @Date:   2020-02-14 20:34:50
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 20:37:55
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

	int max(int a, int b){
		return a > b ? a : b;
	}

    int maxDepth(TreeNode* root) {
        if(root == NULL)	return 0;

        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};

int main()
{
    
    return 0;
}