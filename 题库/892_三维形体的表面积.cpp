/*
* @Author: liaohch3
* @Date:   2020-03-25 17:38:45
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-25 18:15:55
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
public:
    int surfaceArea(vector<vector<int> >& grid) {
    	return surfaceArea2(grid);
    }
    int surfaceArea2(vector<vector<int> >& grid) {
    	int n = grid.size();
    	int res = 0;

    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < n; j++){
    			if(grid[i][j] == 0){
    				continue;
    			}

    			int now = 2;
    			if(i == 0){
    				now += grid[i][j];
    			}else if(grid[i][j] > grid[i-1][j]){
    				now += grid[i][j] - grid[i-1][j];
    			}
    			if(j == 0){
    				now += grid[i][j];
    			}else if(grid[i][j] > grid[i][j-1]){
    				now += grid[i][j] - grid[i][j-1];
    			}
    			if(i == n - 1){
    				now += grid[i][j];
    			}else if(grid[i][j] > grid[i+1][j]){
    				now += grid[i][j] - grid[i+1][j];
    			}
    			if(j == n - 1){
    				now += grid[i][j];
    			}else if(grid[i][j] > grid[i][j+1]){
    				now += grid[i][j] - grid[i][j+1];
    			}

    			res += now;
    		}
    	}

    	return res;
    }
    int surfaceArea1(vector<vector<int> >& grid) {
    	// 法一：不通过，某些内嵌的面找不到
    	int m = grid.size(), n = grid[0].size();

    	// 正视图
    	int zheng = 0;
    	for(int i = 0; i < m; i++){
    		int maxZheng = grid[i][0];
    		for(int j = 1; j < n; j++){
    			maxZheng = max(maxZheng, grid[i][j]);
    		}
    		zheng += maxZheng;
    	}

    	// 侧视图
    	int ce = 0;
    	for(int i = 0; i < n; i++){
    		int maxCe = grid[0][i];
    		for(int j = 1; j < m; j++){
    			maxCe = max(maxCe, grid[j][i]);
    		}
    		ce += maxCe;
    	}

    	// 俯视图
    	int fu = 0;
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(grid[i][j] != 0){
    				fu ++;
    			}
    		}
    	}

    	return 2 * (zheng + ce + fu);
    }
};

int main()
{
    vector<vector<int> > grid = {{2}};
    cout << Solution().surfaceArea(grid) << endl;
    grid = {{1,2}, {3,4}};
    cout << Solution().surfaceArea(grid) << endl;
    grid = {{1,0}, {0,2}};
    cout << Solution().surfaceArea(grid) << endl;
    grid = {{1,1,1}, {1,0,1}, {1,1,1}};
    cout << Solution().surfaceArea(grid) << endl;
    grid = {{2,2,2}, {2,1,2}, {2,2,2}};
    cout << Solution().surfaceArea(grid) << endl;
    return 0;
}