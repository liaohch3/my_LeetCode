/*
* @Author: liaohch3
* @Date:   2020-02-19 11:03:29
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-19 11:06:19
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
    vector<int> reversePrint(ListNode* head) {
        if(head == NULL)	return vector<int>();

        ListNode* p = head;
        stack<int> s;
        while(p){
        	s.push(p->val);
        	p = p->next;
        }
        
        vector<int> res(s.size(), 0);
        int i = 0;
        while(!s.empty()){
        	res[i] = s.top();
        	i++;
        	s.pop();
        }

        return res;
    }
};

int main()
{
    
    return 0;
}