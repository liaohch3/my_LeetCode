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
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
    	map<Node*, Node*> m;
        Node* p = head;
        Node* reshead = new Node(0);
        Node* q = reshead;

        while(p){
        	q->next = new Node(p->val);
        	m[p] = q->next;
        	q = q->next;
        	p = p->next;
        }

        q = reshead;
        reshead = reshead->next;
        delete q;
        q = reshead;
        p = head;

        while(p){
        	if(p->random){
        		q->random = m[p->random];
        	}
        	p = p->next;
        	q = q->next;
        }

        return reshead;
    }
};

int main()
{

	return 0;
}