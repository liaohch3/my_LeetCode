/*
* @Author: liaohch3
* @Date:   2020-03-11 23:00:08
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-11 23:39:40
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
        return getIntersectionNode2(headA, headB);
    }

    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
    	// 法一：哈希集合法
    	unordered_set<ListNode*> hashSet;
        ListNode* p = headA;
        while(p){
        	hashSet.insert(p);
        	p = p->next;
        }

        p = headB;
        while(p){
        	if(hashSet.count(p) == 1){
        		return p;
        	}
        	p = p->next;
        }

        return NULL;
    }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    	// 双指针法
        ListNode* p = headA;
        ListNode* q = headB;
        while(p != q){
        	if(p == NULL){
        		p = headB;
        	}else{
        		p = p->next;
        	}
        	if(q == NULL){
        		q = headA;
        	}else{
        		q = q->next;
        	}
        }
        return p;
   }

};

int main()
{
    
    return 0;
}