/*
* @Author: liaohch3
* @Date:   2020-03-19 14:45:52
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-19 14:50:05
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
    int longestPalindrome(string s) {
    	int alpha[52] = {0};
    	for(char ch: s){
    		if(ch >= 'a' && ch <= 'z'){
    			alpha[ch-'a']++;
    		}else if(ch >= 'A' && ch <= 'Z'){
    			alpha[ch-'A'+26]++;
    		}
    	}

    	bool odd = false;
    	int res = 0;
    	for(int i = 0; i < 52; i++){
    		if(alpha[i] % 2 == 0){
    			res += alpha[i];
    		}else{
    			odd = true;
    			res += alpha[i] - 1;
    		}
    	}

    	if(odd){
    		res++;
    	}

    	return res;
    }
};

int main()
{
    
    return 0;
}