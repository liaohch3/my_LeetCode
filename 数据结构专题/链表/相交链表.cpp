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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;

        int len1 = 0;
        while(p){
            len1++;
            p = p->next;
        }

        int len2 = 0;
        while(q){
            len2++;
            q = q->next;
        }

        p = headA;
        q = headB;
        if(len1 < len2){
            int len = len2 - len1;
            while(len--){
                q = q->next;
            }
        }else{
            int len = len1 - len2;
            while(len--){
                p = p->next;
            }
        }

        while(p && q){
            if(p == q)  
                return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};

int main()
{

    return 0;
}