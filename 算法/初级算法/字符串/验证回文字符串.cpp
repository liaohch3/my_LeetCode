/*
* @Author: liaohch3
* @Date:   2020-02-14 00:10:51
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 00:21:47
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

	bool legal(char ch){
		if(ch >= 'a' && ch <= 'z'){
			return true;
		}else if(ch >= 'A' && ch <= 'Z'){
			return true;
		}else if(ch >= '0' && ch <= '9'){
			return true;
		}else{
			return false;
		}
	}

	bool check(char a, char b){
		if(a >= '0' && a <= '9'){
			return a == b;
		}else{
			if(b >= 'a' && b <= 'z'){
				return b==a+32 || b==a;
			}else if(b >= 'A' && b <= 'Z'){
				return b==a-32 || b==a;
			}else{
				return false;
			}
		}
	}

    bool isPalindrome(string s) {
        if(s.size() <= 1)	return true;
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
        	while(i < j && !legal(s[i]))	i++;
        	while(i < j && !legal(s[j]))	j--;
        	if(i < j){
        		// printf("i: %d-%c, j: %d-%c\n", i, s[i], j, s[j]);
        		if(!check(s[i], s[j])){
        			return false;
        		}
        	}
        	i++;
        	j--;
        }
        return true;
    }
};

int main()
{
    cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << Solution().isPalindrome("race a car") << endl;
    return 0;
}