/*
* @Author: liaohch3
* @Date:   2020-03-30 12:25:22
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-30 16:26:43
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
    int lastRemaining(int n, int m) {
    	return lastRemaining2(n ,m);
    }
    int lastRemaining2(int n, int m) {
    	// 剑指Offer第62题-第302页

    	int res = 0;
    	for(int i = 2; i <= n; i++){
    		res = (res + m) % i;
    	}
    	return res;
    }
    int lastRemaining1(int n, int m) {
    	// 暴力法 超时
    	vector<bool> nums(n, true);

    	int i = 0;
    	int j = 0;
    	int k = 0;
    	while(true){
    		if(nums[j]){
    			k++;
    			if(k == m){
    				k = 0;
	    			nums[j] = false;
	    			// cout << j << endl;
	    			i++;
	    			if(i == n){
	    				return j;
	    			}
    			}
    		}
    		j = (j + 1) % n;
    	}

    	return 0;
    }
};

int main()
{
    cout << Solution().lastRemaining(5, 3) << endl;
    cout << Solution().lastRemaining(10, 17) << endl;

	// for(int i = 1; i <= 10; i++){
	// 	printf("(7, %d): %d\n", i, Solution().lastRemaining(7, i));
	// }


    return 0;
}