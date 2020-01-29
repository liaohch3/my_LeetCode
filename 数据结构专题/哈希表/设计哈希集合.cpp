#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class MyHashSet {
public:

	vector<vector<int> > hashSet;
	int SIZE;

    /** Initialize your data structure here. */
    MyHashSet() {
    	SIZE = 100;
        hashSet.resize(SIZE);
    }
    
    void add(int key) {
    	if(!contains(key))
	        hashSet[key % SIZE].push_back(key);
    }
    
    void remove(int key) {
        for(int i = 0; i < hashSet[key%SIZE].size(); i++){
        	if(hashSet[key%SIZE][i] == key){
        		hashSet[key%SIZE].erase(hashSet[key%SIZE].begin()+i);
        		break;
        	}
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        for(int i = 0; i < hashSet[key%SIZE].size(); i++)
        	if(hashSet[key%SIZE][i] == key)
        		return true;
        return false;
    }
};

void show(vector<vector<int> >& hashSet){
	for(int i = 1; i <= 3; i++){
		for(int j = 0; j < hashSet[i].size(); j++)
			cout << hashSet[i][j] << " ";
		cout << endl;
	}
	cout << "=============================" << endl;
}

int main()
{

	// Your MyHashSet object will be instantiated and called as such:
	MyHashSet* obj = new MyHashSet();
	show(obj->hashSet);
	obj->add(1);
	show(obj->hashSet);
	obj->add(2);
	show(obj->hashSet);
	bool param_1 = obj->contains(1);
	show(obj->hashSet);
	bool param_2 = obj->contains(3);
	show(obj->hashSet);
	obj->add(2);
	show(obj->hashSet);
	bool param_3 = obj->contains(2);
	show(obj->hashSet);
	obj->remove(2);
	show(obj->hashSet);
	bool param_4 = obj->contains(2);
	show(obj->hashSet);

	return 0;
}