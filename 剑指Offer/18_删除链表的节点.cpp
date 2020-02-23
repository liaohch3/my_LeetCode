/*
* @Author: liaohch3
* @Date:   2020-02-22 23:01:01
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-22 23:09:17
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


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
    	if(head->val == val){
    		ListNode* p = head;
    		head = head->next;
    		delete p;
    		return head;
    	}else{
    		ListNode* p = head;
    		while(p->next){
    			if(p->next->val == val){
    				ListNode* temp = p->next;
    				p->next = p->next->next;
    				delete temp;
    				return head;
    			}
    			p = p->next;
    		}
    		return head;
    	}
    }
};

int main()
{
    
    return 0;
}