/*
* @Author: liaohch3
* @Date:   2020-02-22 14:46:56
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-22 14:59:38
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
    int hammingWeight(uint32_t n) {
    	return hammingWeight3(n);
    }

    int hammingWeight1(uint32_t n) {
    	// 有点小问题，如果n为负数将会死循环

        int count = 0;
        while(n){
        	if(n & 1){
                ++count;
            }
        	n >>= 1;
        }
        return count;
    }


    int hammingWeight2(uint32_t n) {
    	// 比较好，但有不足
    	// 这个方法一定会循环32次

    	unsigned int flag = 1;
    	int count = 0;
    	while(flag){
    		if(n & flag){
    			++count;
    		}
    		flag <<= 1;
    	} 
    	return count;
    }

    int hammingWeight3(uint32_t n) {
    	// 这个方法有几个1就循环几次
    	// 思路见《剑指Offer》121页

    	int count = 0;
    	while(n){
    		n &= n - 1;
			++count;
    	}
    	return count;
    }
};

int main()
{
    cout << Solution().hammingWeight(9);
    return 0;
}