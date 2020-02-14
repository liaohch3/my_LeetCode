/*
* @Author: liaohch3
* @Date:   2020-02-14 15:41:27
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 15:56:06
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

    string countAndSay(int n) {
        if(n == 1)	return "1";
        string last = countAndSay(n-1);

        int i = 0;
        string res = "";
        while(i < last.size()){
        	char now = last[i];
        	int count = 1;
        	while(i+1<last.size() && last[i+1]==now){
        		i++;
        		count++;
        	}

        	res += (count + '0');
        	res += now;

        	i++;
        }

        return res;
    }
};

int main()
{
    for(int i = 1; i <= 5; i++){
    	cout << Solution().countAndSay(i) << endl;
    }
    return 0;
}