/*
* @Author: liaohch3
* @Date:   2020-02-22 18:43:42
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-22 23:03:53
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
    vector<int> printNumbers(int n) {
    	if(n == 0)	return vector<int>();

    	// 异常处理，这里也返回空表算了
    	if(n < 0)	return vector<int>();

    	int maxItem = 1;
    	for(int i = 0; i < n; i++){
    		maxItem *= 10;
    	}
    	vector<int> res(maxItem-1, 0);
    	for(int i = 0; i < maxItem-1; i++){
    		res[i] = i + 1;
    	}
    	return res;
    }

    int invalidInput = 0;
    void printNumbers2(int n){
    	if(n == 0)	return;

    	// 异常处理
    	if(n < 0)	invalidInput = 1;
    	string str(n, '0');
    	plusMySting(str, n);
    	cout << str << endl;
    	// printMyString(str, n);
    }

    void plusMySting(string& str, int n)const{
    	int i = n - 1;
    	while(i >= 0){
    		if(str[i] != '9'){
    			str[i]++;
    			return;
    		}else{
    			str[i] = '0';
    			i--;
    		}
    	}
    }

    void printMyString(const string& str, int n)const{
    	int i = 0;
    	while(i < n){
    		if(str[i] == '0'){
    			i++;
    		}
    	}
    	
    	while(i < n){
    		cout << str[i];
    		i++;
    	}

    	cout << endl;
    }
};

int main()
{
	Solution().printNumbers2(2);
    return 0;
}