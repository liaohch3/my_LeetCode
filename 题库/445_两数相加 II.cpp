/*
* @Author: liaohch3
* @Date:   2020-04-14 20:23:50
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-14 20:44:34
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
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

	ListNode* helper(string& a, string& b)const{
		int m = a.size();
		int n = b.size();
		int carry = 0;
		for(int i = m - 1; i >= 0; i--){
			int j = i - (m-n);
			if(j >= 0){
				int temp = a[i]-'0' + b[j]-'0' + carry;
				if(temp >= 10){
					a[i] = temp % 10 + '0';
					carry = 1;
				}else{
					a[i] = temp + '0';
					carry = 0;
				}
			}else{
				if(carry == 0){
					break;
				}else{
					int temp = a[i]-'0' + carry;
					if(temp >= 10){
						a[i] = temp % 10 + '0';
						carry = 1;
					}else{
						a[i] = temp + '0';
						carry = 0;
					}
				}
			}
		}
		if(carry == 1){
			a = "1" + a;
		}

		ListNode* res = new ListNode(a[0]-'0');
		ListNode* p = res;
		for(int i = 1; i < a.size(); i++){
			p->next = new ListNode(a[i]-'0');
			p = p->next;
		}

		return res;
	}

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	string a = "";
    	ListNode* p = l1;
    	while(p){
    		a += p->val + '0';
    		p = p->next;
    	}
    	string b = "";
    	ListNode* q = l2;
    	while(q){
    		b += q->val + '0';
    		q = q->next;
    	}

    	if(a.size() < b.size()){
    		return helper(b, a);
    	}
    	return helper(a, b);
    }
};

int main()
{
    ListNode* p = new ListNode(9);
    p->next = new ListNode(9);
    p->next->next = new ListNode(9);
    p->next->next->next = new ListNode(9);

    ListNode* q = new ListNode(1);
    // q->next = new ListNode(6);
    // q->next->next = new ListNode(3);
    
    ListNode* res = Solution().addTwoNumbers(p, q);
    while(res){
    	cout << res->val;
    	res = res->next;
    } 

    return 0;
}