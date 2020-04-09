/*
* @Author: liaohch3
* @Date:   2020-04-03 17:40:10
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-03 18:43:47
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

	const int START;
	const int SIGNED;
	const int INNUMBER;
	const int END;

	inline bool isDigit(char ch){ return ch >= '0' && ch <= '9'; }

public:

	Solution():START(0), SIGNED(1), INNUMBER(2), END(3){}

    int myAtoi(string str) {
        int status = START;
        bool pos = true;
        int res = 0;

        for(int i = 0; i < str.size(); i++){
        	char ch = str[i];
        	if(status == START){
	        	if(ch == ' ')	continue;
	        	else if(ch == '+' || ch == '-'){
	        		if(ch == '-') {
	        			pos = false;
	        		}
	        		status = SIGNED;
	        	}else if(isDigit(ch)){
	        		res = ch - '0';
	        		status = INNUMBER;
	        	}else{
	        		status = END;
	        	}
        	}else if(status == SIGNED){
        		if(isDigit(ch)){
	        		res = ch - '0';
	        		status = INNUMBER;
        		}else{
        			status = END;
        		}
        	}else if(status == INNUMBER){
        		if(isDigit(ch)){
        			if(res < INT_MAX / 10 || (res == INT_MAX / 10 && ch <= '7')){
	        			res = res * 10 + (ch - '0');
        			}else{
        				if(pos){
        					res = INT_MAX;
        				}else{
        					res = INT_MIN;
        				}
        				status = END;
        				return res;
        			}
        		}else{
        			status = END;
        		}
        	}else if(status == END){

        		break;
        	}
        }

		if(!pos){
			res *= -1;
		}
        return res;
    }
};

int main()
{
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;

	cout << Solution().myAtoi("   -42") << endl;
	cout << Solution().myAtoi("4193 with words") << endl;
	cout << Solution().myAtoi("words and 987") << endl;
	cout << Solution().myAtoi("-91283472332") << endl;
	cout << Solution().myAtoi("  -0012a42") << endl;
	cout << Solution().myAtoi("2147483646") << endl;


    return 0;
}