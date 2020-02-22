/*
* @Author: liaohch3
* @Date:   2020-02-22 15:20:15
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-22 18:43:23
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
    double myPow(double x, int nn) {

    	long long n = nn;
    	if(n == 0)	return 1;

    	bool pos = true;
    	if(n < 0){
    		pos = false;
    		n *= -1;
    	}

    	double carry = 1.0;

    	while(n != 1){
    		if(n % 2 == 1){
    			carry *= x;
    			n--;
    		}

    		x *= x;
    		n /= 2;
    	}
    	if(pos){
    		return x * carry;
    	}else{
    		return 1/ (x * carry);
    	}
    }
};

int main()
{
    cout << Solution().myPow(2.1, 3) << endl;
    cout << Solution().myPow(2, 10) << endl;
    cout << Solution().myPow(2, -2) << endl;
    return 0;
}