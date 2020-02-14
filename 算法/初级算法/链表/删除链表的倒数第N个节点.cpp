/*
* @Author: liaohch3
* @Date:   2020-02-14 16:02:14
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 16:07:41
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode* p = head;
    	ListNode* q = head;

    	while(n--){
    		p = p->next;
    	}

    	if(p == NULL){
    		head = q->next;
    		delete q;
    		return head;
    	}

    	while(p->next){
    		p = p->next;
    		q = q->next;
    	}
    	p = q->next;
    	q->next = q->next->next;
    	delete p;
    	return head;
    }
};

int main()
{
    
    return 0;
}