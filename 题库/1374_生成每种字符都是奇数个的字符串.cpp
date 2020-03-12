/*
* @Author: liaohch3
* @Date:   2020-03-12 17:20:33
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-12 17:31:53
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
    string generateTheString(int n) {
    	if(n == 0)	return "";
    	if(n % 2 == 1){
    		return string(n, 'a');
    	}else{
    		return string(n-1, 'a') + "b";
    	}
    }
};

int main()
{
    cout << Solution().generateTheString(4) << endl;
    cout << Solution().generateTheString(2) << endl;
    cout << Solution().generateTheString(7) << endl;
    cout << Solution().generateTheString(78) << endl;
    return 0;
}