/*
* @Author: liaohch3
* @Date:   2020-02-19 14:38:42
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-19 14:48:27
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

class CQueue {
	stack<int> s1;
	stack<int> s2;
public:
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
    	if(!s1.empty() || !s2.empty()){
			if(s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}
			int res = s2.top();
			s2.pop();
			return res;
    	}else{
    		return -1;
    	}
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
	CQueue* obj = new CQueue();
	obj->appendTail(1);
	int param_2 = obj->deleteHead();
    return 0;
}