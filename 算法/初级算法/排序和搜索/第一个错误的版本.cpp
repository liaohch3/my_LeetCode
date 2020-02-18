/*
* @Author: liaohch3
* @Date:   2020-02-14 21:52:39
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 21:58:45
*/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
    	long long i = 1;
    	long long j = n;

    	while(i < j){
    		long long mid = i + (j - i) / 2;
    		if(isBadVersion(mid)){
    			j = mid;
    		}else{
    			i = mid + 1;
    		}
    	}

    	return i;
    }
};


int main()
{
    
    return 0;
}