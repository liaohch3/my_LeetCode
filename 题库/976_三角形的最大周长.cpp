/*
* @Author: liaohch3
* @Date:   2020-03-23 18:38:59
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-23 18:56:05
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
	bool legal(const int& a, const int& b, const int& c){
		if(a + b <= c)	return false;
		if(a + c <= b)	return false;
		if(b + c <= a)	return false;
		return true;
	}
public:
    int largestPerimeter(vector<int>& A) {
    	sort(A.begin(), A.end());

    	int i = 0;
    	int j = A.size() - 1;
    	int res = 0;
    	while(i < j){
    		
    	}

    }
};

int main()
{
    
    return 0;
}