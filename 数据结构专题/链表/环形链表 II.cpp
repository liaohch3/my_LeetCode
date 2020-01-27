#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 这题好，参考博客https://blog.csdn.net/Eric_qiushui/article/details/89224663

        if(head == NULL || head->next == NULL)  return NULL;

        ListNode* p = head;
        ListNode* q = head;

        while(p && q){

            p = p->next;
            q = q->next;
            if(q != NULL)
                q = q->next;
            else
                return NULL;
            if(p == q)  break;
        }
        if(!p || !q)
            return NULL;

        p = head;
        while(p != q){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};

int main()
{

    return 0;
}