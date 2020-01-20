#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

/*
说明:

你只能使用标准的栈操作 -- 
也就是只有 push to top, peek/pop from top, 
size, 和 is empty 操作是合法的。

你所使用的语言也许不支持栈。你可以使用 list 或者 
deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

假设所有操作都是有效的 （例如，一个空的队列不会调用 
pop 或者 peek 操作）。
*/

class MyQueue {
public:

	stack<int> a;
	stack<int> b;

    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(b.empty())
        {
        	while(!a.empty())
        	{
        		b.push(a.top());
        		a.pop();
        	}
        }
    	int res = b.top();
    	b.pop();
    	return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(b.empty())
        {
        	while(!a.empty())
        	{
        		b.push(a.top());
        		a.pop();
        	}
        }
    	return b.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty() && b.empty();
    }
};


int main()
{
	//Your MyQueue object will be instantiated and called as such:
	MyQueue* obj = new MyQueue();
	obj->push(1);
	int param_2 = obj->pop();
	int param_3 = obj->peek();
	bool param_4 = obj->empty();
	return 0;
}