/*
* @Author: liaohch3
* @Date:   2020-04-20 12:46:53
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-20 12:54:56
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

	void helper(vector<vector<char> >& grid, int i, int j){
		int m = grid.size();
		int n = grid[0].size();
		if(i + 1 < m && grid[i+1][j] == '1'){
			grid[i+1][j] = '0';
			helper(grid, i+1, j);
		}
		if(j + 1 < n && grid[i][j+1] == '1'){
			grid[i][j+1] = '0';
			helper(grid, i, j+1);
		}
		if(i - 1 >= 0 && grid[i-1][j] == '1'){
			grid[i-1][j] = '0';
			helper(grid, i-1, j);
		}
		if(j - 1 >= 0 && grid[i][j-1] == '1'){
			grid[i][j-1] = '0';
			helper(grid, i, j-1);
		}
	}

public:
    int numIslands(vector<vector<char> >& grid) {
    	if (grid.empty() || grid[0].empty()){
    		return 0;
    	}
		int m = grid.size();
		int n = grid[0].size();

    	int res = 0;
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(grid[i][j] == '1'){
    				res++;
    				helper(grid, i, j);
    			}
    		}
    	}
    	
    	return res;
    }
};

int main()
{
    
    return 0;
}