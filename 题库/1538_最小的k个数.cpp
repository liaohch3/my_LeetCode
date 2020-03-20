/*
* @Author: liaohch3
* @Date:   2020-03-20 14:07:45
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-20 14:55:16
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

    	if(k == 0){
    		return vector<int>();
    	}

    	priority_queue<int> q;
    	for(int item: arr){
    		if(q.size() < k){
    			q.push(item);
    		}else if(item < q.top()){
    			q.pop();
    			q.push(item);
    		}
    	}

    	vector<int> res(k);
    	for(int i = 0; i < k; i++){
    		res[i] = q.top();
    		q.pop();
    	}

    	return res;
    }
};

int main()
{
    
    return 0;
}