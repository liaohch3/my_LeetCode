/*
* @Author: liaohch3
* @Date:   2020-02-14 20:29:35
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 20:34:26
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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)  return false;
        ListNode* p = head;
        ListNode* q = head;
        while(p && q){
            p = p->next;
            q = q->next;
            if(q){
                q = q->next;
            }else{
                return false;
            }
            if(p == q){
                return true;
            }
        }
        return false;
    }
};


int main()
{
    
    return 0;
}