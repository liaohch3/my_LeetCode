/*
* @Author: liaohch3
* @Date:   2020-02-23 00:27:15
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-23 14:27:43
*/

#include <iostream>
#include <stack>
#include <string>
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
    bool isMatch(string s, string p) {
    	return isMatch1(s, p);
    }

    bool isMatch1(string s, string p) {

    	// 递归算法 见：https://www.bilibili.com/video/av66324687?from=search&seid=15783022143620849985

    	if(p.empty()){
    		return s.empty();
    	}

    	bool firstMatch = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
    	if(p.size() >= 2 && p[1] == '*'){
    		return isMatch1(s, p.substr(2)) || 	(firstMatch && isMatch1(s.substr(1), p));
    	}else{
    		return firstMatch && isMatch1(s.substr(1), p.substr(1));
    	}
    }
};

int main()
{
    
	cout << Solution().isMatch(string("aa"), string("a")) << endl;
	cout << Solution().isMatch(string("aa"), string("a*")) << endl;
	cout << Solution().isMatch(string("ab"), string(".*")) << endl;
	cout << Solution().isMatch(string("aab"), string("c*a*b")) << endl;
    return 0;
}