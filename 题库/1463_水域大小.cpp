/*
* @Author: liaohch3
* @Date:   2020-03-14 12:35:31
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-14 12:45:30
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

	int getOneSize(vector<vector<int> >& land, int x, int y){
		if(x >= 0 && y >= 0 && x < land.size() && y < land[0].size() && land[x][y] == 0){
			land[x][y] = -1;
			return 1 
			+ getOneSize(land, x+1, y+1)
			+ getOneSize(land, x+1, y-1)
			+ getOneSize(land, x+1, y)
			+ getOneSize(land, x, y+1)
			+ getOneSize(land, x, y-1)
			+ getOneSize(land, x-1, y+1)
			+ getOneSize(land, x-1, y-1)
			+ getOneSize(land, x-1, y)
			;
		}else{
			return 0;
		}
	}

    vector<int> pondSizes(vector<vector<int> >& land) {
    	priority_queue<int, vector<int>, greater<int> > q;
    	for(int i = 0; i < land.size(); i++){
    		for(int j = 0; j < land[0].size(); j++){
    			if(land[i][j] == 0){
    				q.push(getOneSize(land, i, j));
    			}
    		}
    	}
    	vector<int> res(q.size());
    	for(int i = 0; i < res.size(); i++){
    		res[i] = q.top();
    		q.pop();
    	}
    	return res;
    }
};

int main()
{
    
    return 0;
}