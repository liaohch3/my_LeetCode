#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class RandomizedSet {
public:

	unordered_set<int> hashSet;

    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashSet.count(val) == 0){
        	hashSet.insert(val);
        	return true;
        }
        else
	        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hashSet.count(val) == 1){
        	hashSet.erase(val);
        	return true;
        }
        else
	        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int item = rand() % hashSet.size();
        int i = 0;
        for(auto it: hashSet){
        	if(i == item)
        		return it;
        	i++;
        }
        return *hashSet.begin();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
	return 0;
}