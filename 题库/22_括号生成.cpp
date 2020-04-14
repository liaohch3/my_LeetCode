/*
* @Author: liaohch3
* @Date:   2020-04-09 15:07:14
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-09 21:22:26
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

	void helper(vector<string>& res, int left, int right, string now, int l, int r){
		if(left > 0 || right > 0){
			if(left > 0){
				helper(res, left-1, right, now+"(", l+1, r);
			}
			if(right > 0 && l > r){
				helper(res, left, right-1, now+")", l, r+1);
			}
		}else{
			res.push_back(now);
		}
	}

public:
    vector<string> generateParenthesis(int n) {
        if(n == 0){
        	return vector<string>();
        }

        vector<string> res;
        helper(res, n-1, n, "(", 1, 0);

        return res;
    }
};

int main()
{
    vector<string> res = Solution().generateParenthesis(3);
    
    for(auto& str: res){
    	cout << str << endl;
    }

    return 0;
}