/*
* @Author: liaohch3
* @Date:   2020-04-08 15:54:42
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-08 17:12:37
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
	inline int count(const int& a, const int& b)const{
		return (a % 10) + (a / 10) % 10 + (a / 100) % 10 + (b % 10) + (b / 10) % 10 + (b / 100) % 10;
	}

	int m, n, k, res;

	void dfs(int x, int y, vector<vector<bool> >& visited){
		if(x < m && y < n && visited[x][y] == false && count(x, y) <= k){
			res++;
			visited[x][y] = true;
			dfs(x+1, y, visited);
			dfs(x, y+1, visited);
		}
	}

public:
    int movingCount(int m, int n, int k) {
    	if(m == 0 || n == 0)	return 0;

    	vector<vector<bool> > visited(m, vector<bool>(n, false)); 
    	this->m = m;
    	this->n = n;
    	this->k = k;
    	res = 0;

    	dfs(0, 0, visited);

    	return res;
    }
};

int main()
{
    cout << Solution().movingCount(2, 3, 1) << endl;
    cout << Solution().movingCount(3, 1, 0) << endl;
    cout << Solution().movingCount(1, 2, 1) << endl;
    return 0;
}