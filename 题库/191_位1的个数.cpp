/*
* @Author: liaohch3
* @Date:   2020-03-18 16:36:11
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-18 16:37:09
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
    int hammingWeight(uint32_t n) {
    	int res = 0;

        while(n){
        	n &= n-1;
        	++res;
        }

        return res;
    }
};

int main()
{
    
    return 0;
}