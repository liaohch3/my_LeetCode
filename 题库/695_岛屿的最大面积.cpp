/*
* @Author: liaohch3
* @Date:   2020-03-15 17:13:35
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-15 17:18:20
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

	int areaOfIsland(vector<vector<int> >& grid, int x, int y){
		grid[x][y] = 0;
		int res = 1;
		if(x - 1 >= 0 && grid[x - 1][y] == 1){
			res += areaOfIsland(grid, x - 1, y);
		}
		if(y - 1 >= 0 && grid[x][y - 1] == 1){
			res += areaOfIsland(grid, x, y - 1);
		}
		if(x + 1 < grid.size() && grid[x + 1][y] == 1){
			res += areaOfIsland(grid, x + 1, y);
		}
		if(y + 1 < grid[0].size() && grid[x][y + 1] == 1){
			res += areaOfIsland(grid, x, y + 1);
		}
		return res;
	}

    int maxAreaOfIsland(vector<vector<int> >& grid) {
    	int maxSize = 0;
    	for(int i = 0; i < grid.size(); i++){
    		for(int j = 0; j < grid[0].size(); j++){
    			if(grid[i][j] == 1){
    				maxSize = max(maxSize, areaOfIsland(grid, i, j));
    			}
    		}
    	}
    	return maxSize;
    }
};

int main()
{
    
    return 0;
}