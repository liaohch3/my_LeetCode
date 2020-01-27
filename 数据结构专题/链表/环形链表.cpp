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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)  return false;

        ListNode* p = head;
        ListNode* q = head;

        while(p && q){

            p = p->next;
            q = q->next;
            if(q != NULL)
                q = q->next;
            else
                break;
            if(p == q)  return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}