#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
    	if(head == NULL)	return head;

    	Node* p = head;
    	while(p){

    		if(p->child != NULL){
    			Node* q = p->child;
    			Node* m = p->next;

    			p->next = q;
    			q->prev = p;
    			p->child = NULL;

    			while(q->next){
    				q = q->next;
    			}
    			q->next = m;
    			if(m)
	    			m->prev = q;
    		}

    		p = p->next;
    	}

    	return head;
    }
};

int main()
{
	return 0;
}