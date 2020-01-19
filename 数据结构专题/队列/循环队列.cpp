#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
    int *circularQueue;
    int size;
    int head;
    int tail;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
        circularQueue = new int[k];
        head = -1;
        tail = -1;
    }

    ~MyCircularQueue() {
        delete [] circularQueue;
    }
    
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
            return false;
        tail = (tail + 1) % size;
        circularQueue[tail] = value;
        if(head == -1)
            head = 0;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;
        head = (head + 1) % size;
        if(head == (tail + 1) % size)
        {
            head = -1;
            tail = -1;
        }
        return true;
    }
    
    /** Get the head item from the queue. */
    int Front() {
    	if(isEmpty())
    		return -1;
        return circularQueue[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
    	if(isEmpty())
    		return -1;
        return circularQueue[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(head == -1 && tail == -1)
        	return true;
        else
        	return false;	
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if((tail + 1) % size == head)
        	return true;
        else
        	return false;
    }
};


int main(){
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 */
 
	MyCircularQueue* obj = new MyCircularQueue(5);
	bool param_1 = obj->enQueue(2);
	bool param_2 = obj->deQueue();
	int param_3 = obj->Front();
	int param_4 = obj->Rear();
	bool param_5 = obj->isEmpty();
	bool param_6 = obj->isFull();

	return 0;
}

