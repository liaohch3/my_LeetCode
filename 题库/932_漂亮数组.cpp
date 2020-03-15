/*
* @Author: liaohch3
* @Date:   2020-03-15 17:29:39
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-15 21:01:29
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

	unordered_map<int, vector<int> > hashMap;

    vector<int> beautifulArray(int N) {
    	if(hashMap.find(N) != hashMap.end()){
    		return hashMap[N];
    	}
    	if(N == 1){
    		hashMap[1] = vector<int>(1, 1);
    		return hashMap[1];
    	}
    	vector<int> res(N);
    	vector<int> odds = beautifulArray((N+1)/2);
    	vector<int> evens = beautifulArray(N/2);
    	int i = 0;
    	for(int item: odds){
    		res[i++] = 2 * item - 1;
    	}
    	for(int item: evens){
    		res[i++] = 2 * item;
    	}
    	return res;
    }
};

int main()
{
    vector<int> v1 = Solution().beautifulArray(4);
    vector<int> v2 = Solution().beautifulArray(5);
    
    return 0;
}