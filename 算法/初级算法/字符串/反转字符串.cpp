/*
* @Author: liaohch3
* @Date:   2020-02-13 23:35:58
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-13 23:37:52
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
    void reverseString(vector<char>& s) {
    	int n = s.size();
    	if(n <= 1)	return;
    	for(int i = 0; i < n / 2; i++){
    		char temp = s[i];
    		s[i] = s[n-1-i];
    		s[n-1-i] = temp;
    	}
    }
};


int main()
{
    
    return 0;
}