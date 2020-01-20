#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
	vector<int> min_stack;
	vector<int> stack;

    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        stack.push_back(x);
        if(min_stack.empty() || x <= min_stack.back())
        	min_stack.push_back(x);
    }
    
    void pop() {
		int back = stack.back();
		stack.pop_back();
		if(back == min_stack.back())
			min_stack.pop_back();        
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min_stack.back();
    }
};

class MinStack1 {
public:

	// 差的做法
	vector<int> minStack;
	int minValue;
    /** initialize your data structure here. */
    MinStack1() {
        minValue = 0x7fffffff;
    }
    
    void push(int x) {
        minStack.push_back(x);
        minValue = x < minValue ? x : minValue;
    }
    
    void pop() {
    	int last = minStack.back();
    	minStack.pop_back();
		minValue = 0x7fffffff;
    	for(int i = 0; i < minStack.size(); i++)
        	minValue = minStack[i] < minValue ? minStack[i] : minValue;
    }
    
    int top() {
        return minStack.back();
    }
    
    int getMin() {
        return minValue;
    }
};


int main()
{
	// MinStack* obj = new MinStack();
	// obj->push(0);
	// obj->push(1);
	// obj->push(0);
	// int param_4 = obj->getMin();	
	// obj->pop();
	// int param_5 = obj->getMin();	
	return 0;
}