#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void show(ListNode* head){
    ListNode* p = head;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

class Solution {
public:

    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL)  return head;

        ListNode* p = head;
        int len = 1;
        while(p->next){
            p = p->next;
            len++;
        }
        p->next = head;

        p = head;
        k %= len;
        int step = len - k - 1;
        while(step--){
            p = p->next;
        } 

        ListNode* q = p->next;
        p->next = NULL;
        head = q;
        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;

    Solution().rotateRight(head, 4);

    return 0;
}