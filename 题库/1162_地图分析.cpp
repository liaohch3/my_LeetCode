/*
* @Author: liaohch3
* @Date:   2020-03-29 13:50:27
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-29 16:10:04
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
    int maxDistance(vector<vector<int> >& grid) {
    	int n = grid.size();

		queue<int> q;

		int sum = 0;
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < n; j++){
    			sum += grid[i][j];
    			if(grid[i][j] == 1){
    				q.push(i*n+j);
    			}
    		}
    	}
    	if(sum == 0 || sum == n * n){
    		return -1;
    	}

		int d = 0;

		while(!q.empty()){
			int size = q.size();
			for(int i = 0; i < size; i++){
				int front = q.front();
				q.pop();
				int x = front / n;
				int y = front % n;

			 	if(x-1>=0 && grid[x-1][y] == 0){
			 		q.push((x-1)*n+y);
			 		grid[x-1][y] = 2;
			 	}
			 	if(y-1>=0 && grid[x][y-1] == 0){
			 		q.push((x)*n+y-1);
			 		grid[x][y-1] = 2;
			 	}
			 	if(x+1<n && grid[x+1][y] == 0){
			 		q.push((x+1)*n+y);
			 		grid[x+1][y] = 2;
			 	}
			 	if(y+1<n && grid[x][y+1] == 0){
			 		q.push((x)*n+y+1);
			 		grid[x][y+1] = 2;
			 	}
			}

			d++;
		}

		return d-1;
    }
};

int main()
{

	vector<vector<int> > grid = {{0,0,1,1,1},{0,1,1,0,0},{0,0,1,1,0},{1,0,0,0,0},{1,1,0,0,1}};
    cout << Solution().maxDistance(grid) << endl;
    grid = {{1,0,1}, {0,0,0}, {1,0,1}};
    cout << Solution().maxDistance(grid) << endl;
    grid = {{1,0,0}, {0,0,0}, {0,0,0}};
    cout << Solution().maxDistance(grid) << endl;

    return 0;
}