/*
* @Author: liaohch3
* @Date:   2020-02-19 15:10:56
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-19 15:18:11
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

class Solution {
public:
    int numWays(int n) {
    	if(n == 0)	return 1;
        if(n <= 2)	return n;

        int a = 1;
        int b = 2;
        int res = 0;
        for(int i = 3; i <= n; i++){
        	res = (a + b) % 1000000007;
        	a = b;
        	b = res;
        }

        return res;
    }
};

int main()
{
    cout << Solution().numWays(7) << endl;
    return 0;
}