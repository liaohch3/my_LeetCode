#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class MyHashMap {
public:

	vector<vector<int> > hashKey;
	vector<vector<int> > hashValue;
	int SIZE;

    /** Initialize your data structure here. */
    MyHashMap() {
        SIZE = 100;
        hashKey.resize(SIZE);
        hashValue.resize(SIZE);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        for(int i = 0; i < hashKey[key%SIZE].size(); i++){
        	if(hashKey[key%SIZE][i] == key){
        		hashValue[key%SIZE][i] = value;
        		return;
        	}
        }
        hashKey[key%SIZE].push_back(key);
        hashValue[key%SIZE].push_back(value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for(int i = 0; i < hashKey[key%SIZE].size(); i++){
        	if(hashKey[key%SIZE][i] == key)
        		return hashValue[key%SIZE][i];
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        for(int i = 0; i < hashKey[key%SIZE].size(); i++){
        	if(hashKey[key%SIZE][i] == key){
        		hashKey[key%SIZE].erase(hashKey[key%SIZE].begin()+i);
        		hashValue[key%SIZE].erase(hashValue[key%SIZE].begin()+i);
        	}
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{
	return 0;
}