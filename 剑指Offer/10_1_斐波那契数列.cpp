/*
* @Author: liaohch3
* @Date:   2020-02-19 14:53:49
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-19 15:10:31
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
    int fib(int n) {
        if(n <= 1)	return n;
        long long  a = 0;
        long long  b = 1;
        long long res = 0;
        for(int i = 2; i <= n; i++){
        	res = (a + b )% 1000000007;
        	a = b;
        	b = res;
        }
        return res % 1000000007;
    }
};
int main()
{
    for(int i = 0; i < 9; i ++){
    	cout << Solution().fib(i) << endl;
    }
    return 0;
}