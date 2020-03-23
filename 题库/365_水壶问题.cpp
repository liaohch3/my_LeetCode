/*
* @Author: liaohch3
* @Date:   2020-03-21 12:29:01
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-21 13:11:39
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

struct pair_hash {
    inline size_t operator()(const pair<int,int> & p) const {
        return p.first * 100000 + p.second;
    }
};

class Solution {

	int x;
	int y;
	int z;
	// unordered_set<pair<int, int>, pair_hash> hashSet;
	bool helper(){


        auto hash_function = [](const pair<int, int>& o) {return hash<int>()(o.first) ^ hash<int>()(o.second);};
        unordered_set<pair<int, int>, decltype(hash_function)> hashSet(0, hash_function);

		queue<pair<int, int> > q;
		q.push(make_pair(0, 0));
		hashSet.insert(make_pair(0, 0));

		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			int first = p.first;
			int second = p.second;

			if(first + second == z){
				return true;
			}

			if(hashSet.count(make_pair(x, second)) == 0){
	    		q.push(make_pair(x, second));
	    		hashSet.insert(make_pair(x, second));
	    	}
	    	if(hashSet.count(make_pair(first, y)) == 0){
	    		q.push(make_pair(first, y));
	    		hashSet.insert(make_pair(first, y));
	    	}
	    	if(hashSet.count(make_pair(0, second)) == 0){
	    		q.push(make_pair(0, second));
	    		hashSet.insert(make_pair(0, second));
	    	}
	    	if(hashSet.count(make_pair(first, 0)) == 0){
	    		q.push(make_pair(first, 0));
	    		hashSet.insert(make_pair(first, 0));
	    	}

	    	if(first < x){
	    		int left = min(x - first, second);
	    		if(hashSet.count(make_pair(first+left, second-left)) == 0){
		    		q.push(make_pair(first+left, second-left));
		    		hashSet.insert(make_pair(first+left, second-left));
	    		}
	    	}
	    	if(second < y){
	    		int left = min(y - second, first);
	    		if(hashSet.count(make_pair(first-left, second+left)) == 0){
		    		q.push(make_pair(first-left, second+left));
		    		hashSet.insert(make_pair(first-left, second+left));
	    		}
	    	}
		}

    	return false;
	}

public:
    bool canMeasureWater(int x, int y, int z) {
    	if(z == 0){
    		return true;
    	}

    	this-> x = x;
    	this-> y = y;
    	this-> z = z;
    	return helper();
    }
};

int main()
{
    cout << __gcd(15, 5) << endl;
    return 0;
}