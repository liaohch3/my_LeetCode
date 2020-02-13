/*
* @Author: liaohch3
* @Date:   2020-02-13 23:39:11
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-13 23:48:59
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
    int reverse(int x) {
        long long res = 0;
        long long t = x;
        while(t){
            res = res * 10 + t % 10;
            t /= 10;
        }

        if(res < INT_MIN || res > INT_MAX){
            return 0;
        }

        return res;
    }
};

int main()
{

    cout << Solution().reverse(123) << endl;
    cout << Solution().reverse(321) << endl;
    cout << Solution().reverse(-123) << endl;
    cout << Solution().reverse(-321) << endl;
    cout << Solution().reverse(120) << endl;
    return 0;
}