/*
* @Author: liaohch3
* @Date:   2020-02-15 11:13:55
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-15 11:30:53
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
    int climbStairs(int n) {
        if(n == 1)	return 1;
        if(n == 2)	return 2;

        int now = 3;
        int res = 0;
        int a = 1;
        int b = 2;
        while(now <= n){
        	res = a + b;
        	a = b;
        	b = res;
        	now++;
        }

        return res;
    }
};

int main()
{
	for(int i = 1; i < 10; i++){
		cout << i << " " << Solution().climbStairs(i) << endl;
	}   
    return 0;
}