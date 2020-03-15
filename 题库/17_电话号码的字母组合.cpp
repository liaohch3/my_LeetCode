/*
* @Author: liaohch3
* @Date:   2020-03-14 13:40:49
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-14 14:23:17
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

	vector<string> alphas;
	Solution(){
		alphas = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	}

    vector<string> letterCombinations(string digits) {
    	if(digits.size() == 0)	return vector<string>();

    	vector<string> next = letterCombinations(digits.substr(1));


    	string now = alphas[digits[0] - '0'];
    	if(digits[0] == '1'){
    		return next;
    	}
    	if(next.size() == 0){
    		vector<string> temp(now.size());
    		for(int i = 0; i < now.size(); i++){
    			temp[i] = now.substr(i, 1);
    		}
    		return temp;
    	}

    	vector<string> res;
    	for(int i = 0; i < now.size(); i++){
    		for(int j = 0; j < next.size(); j++){
    			res.push_back(now.substr(i, 1) + next[j]);
    		}
    	}
    	return res;
    }
};

int main()
{
    vector<string> res = Solution().letterCombinations("234");
    for(auto item : res){
    	cout << item << endl;
    }
    return 0;
}