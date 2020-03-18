/*
* @Author: liaohch3
* @Date:   2020-03-18 15:43:33
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-18 16:52:45
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
    vector<int> countBits(int num) {
    	vector<int> res(num+1, 0);

    	for(int i = 1; i <= num; i++){
    		res[i] = res[i&(i-1)] + 1;
    	}

    	return res;
    }
};

int main()
{
    
    return 0;
}