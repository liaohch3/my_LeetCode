/*
* @Author: liaohch3
* @Date:   2020-03-16 11:20:39
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-16 11:28:27
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

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
        bool flag1 = true;
        bool flag2 = true;

        while(p && q){
        	if(p == q){
        		return p;
        	}

        	p = p->next;
        	q = q->next;

        	if(flag1 && p == NULL){
        		p = headB;
        		flag1 = false;
        	}
        	if(flag2 && q == NULL){
        		q = headA;
        		flag2 = false;
        	}
        }

        return NULL;
    }
};

int main()
{
    
    return 0;
}