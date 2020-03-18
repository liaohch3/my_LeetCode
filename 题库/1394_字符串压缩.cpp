/*
* @Author: liaohch3
* @Date:   2020-03-16 11:33:21
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-16 11:51:15
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
    string compressString(string S) {
    	if(S.size() <= 1) return S;
    		
    	char ch = S[0];
    	int now = 1;
    	string res = "";
    	for(int i = 1; i < S.size(); i++){
    		if(ch == S[i]){
    			now++;
    		}
    		else{
    			res += ch;
    			res += to_string(now);
    			now = 1;
    			ch = S[i];
    		}
    	}

		res += ch;
		res += to_string(now);
		
    	if(res.size() < S.size()){
    		return res;
    	}else{
    		return S;
    	}
    }
};

int main()
{
    cout << Solution().compressString("aabcccccaaa") << endl;
    cout << Solution().compressString("abbccd") << endl;

    return 0;
}