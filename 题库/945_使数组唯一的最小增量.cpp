/*
* @Author: liaohch3
* @Date:   2020-03-22 19:07:35
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-22 19:16:06
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

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
    	return minIncrementForUnique2(A);
    }
    int minIncrementForUnique1(vector<int>& A) {
    	// 暴力法 超时
    	unordered_set<int> hashSet;
    	int res = 0;
    	for(int item: A){
    		if(hashSet.count(item) == 0){
    			hashSet.insert(item);
    		}else{
    			int now = 1;
    			while(hashSet.count(item+now) == 1){
    				now++;
    			}
    			hashSet.insert(item+now);
    			res += now;
    		}
    	}

    	return res;
    }
    int minIncrementForUnique2(vector<int>& A) {
    	// 排序法
    	sort(A.begin(), A.end());
    	int res = 0;
    	for(int i = 1; i < A.size(); i++){
    		if(A[i] <= A[i-1]){
    			res += A[i-1] + 1 - A[i];
    			A[i] = A[i-1] + 1;
    		}
    	}

    	return res;
    }
};

int main()
{
    
    return 0;
}