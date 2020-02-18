/*
* @Author: liaohch3
* @Date:   2020-02-19 00:02:29
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-19 00:07:52
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
    string replaceSpace(string s) {
    	int count = 0;
        for(char ch: s){
        	if(ch == ' '){
        		count++;
        	}
        }
        int oldSize = s.size();
        int newSize = oldSize + 2 * count;
        s.resize(newSize);

        int i = newSize - 1;
        int j = oldSize - 1;
        while(j >= 0){
        	if(s[j] != ' '){
        		s[i--] = s[j];
        	}else{
        		s[i--] = '0';
        		s[i--] = '2';
        		s[i--] = '%';
        	}
        	j--;
        }

        return s;
    }
};

int main()
{
	string s("hello world. ");
	cout << Solution().replaceSpace(s) << endl;
    return 0;
}