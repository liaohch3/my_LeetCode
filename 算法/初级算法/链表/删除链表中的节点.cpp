/*
* @Author: liaohch3
* @Date:   2020-02-14 15:56:21
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 16:01:45
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* p = node;
        p->val = p->next->val;
        ListNode* q = p->next;
        p->next = p->next->next;
        delete q;
    }
};

int main()
{
    
    return 0;
}