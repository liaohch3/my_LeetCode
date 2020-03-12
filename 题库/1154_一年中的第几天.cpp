/*
* @Author: liaohch3
* @Date:   2020-03-12 18:38:38
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-12 18:44:49
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

	bool isLeap(int year){
		return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
	}

    int dayOfYear(string date) {
    	int year = stoi(date.substr(0, 4).c_str());
    	int month = stoi(date.substr(5, 2).c_str());
    	int day = stoi(date.substr(8, 2).c_str());

    	bool leap = isLeap(year);
    	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    	if(leap){
    		days[1]++;
    	}

    	int res = 0;
    	for(int i = 0; i < month-1; i++){
    		res += days[i];
    	}

    	return res + day;
    }	
};

int main()
{
    cout << Solution().dayOfYear("2019-01-09") << endl;
    return 0;
}