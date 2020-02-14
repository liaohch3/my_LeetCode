/*
* @Author: liaohch3
* @Date:   2020-02-14 14:45:38
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 15:32:52
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
    int myAtoi(string str) {
        if(str.size() == 0) return 0;
        int i = 0;
        int pos = 1;
        while(i < str.size()){
            if(str[i] == '-'){
                pos = -1;
                i++;
                break;
            }else if(str[i] == '+'){
                i++;
                break;
            }else if(str[i] >= '0' && str[i] <= '9'){
                break;
            }else if(str[i] == ' '){
                i++;
            }else{
                return 0;
            }
        }

        long long res = 0;
        while(i < str.size()){
            if(str[i] >= '0' && str[i] <= '9'){
                res = res * 10 + str[i] - '0';
                i++;
                if(pos * res < INT_MIN){
                    return INT_MIN;
                }else if(pos * res > INT_MAX){
                    return INT_MAX;
                }
            }else{
                break;
            }
        }

        if(pos * res < INT_MIN){
            return INT_MIN;
        }else if(pos * res > INT_MAX){
            return INT_MAX;
        }else{
            return pos * res;
        }
    }
};

int main()
{
    // cout << Solution().myAtoi("42") << endl;
    // cout << Solution().myAtoi("   -42") << endl;
    // cout << Solution().myAtoi("4193 with words") << endl;
    // cout << Solution().myAtoi("words and 987") << endl;
    cout << Solution().myAtoi("-91283472332") << endl;
    
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;

    return 0;
}