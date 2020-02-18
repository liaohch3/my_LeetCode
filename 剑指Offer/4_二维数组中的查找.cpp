/*
* @Author: liaohch3
* @Date:   2020-02-18 22:47:12
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-18 23:48:18
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
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        return findNumberIn2DArray2(matrix, target);
    }

	struct pari_hash
	{
		inline size_t operator()(const pair<int,int> & p) const {
	        return p.first*10000 + p.second;
	    }
	};

    bool findNumberIn2DArray1(vector<vector<int> >& matrix, int target) {
    	// 广搜，有点慢
    	if(matrix.empty() || matrix[0].empty() || target > matrix.back().back())
    		return false;

        queue<pair<int, int> > q;
        unordered_set<pair<int, int>, pari_hash> visited;
        q.push(make_pair(0, 0));
        visited.insert(make_pair(0, 0));

        while(!q.empty()){
        	int size = q.size();
        	for(int i = 0; i < size; i++){
        		pair<int, int> p = q.front();
        		q.pop();
        		int x = p.first;
        		int y = p.second;
        		if(matrix[x][y] == target){
        			return true;
        		}
        		if(x + 1 < matrix.size() && matrix[x+1][y] <= target && visited.count(make_pair(x+1, y)) == 0){ //
        			q.push(make_pair(x+1, y));
        			visited.insert(make_pair(x+1, y));
        		}
        		if(y + 1 < matrix[0].size() && matrix[x][y+1] <= target && visited.count(make_pair(x, y+1)) == 0){//
        			q.push(make_pair(x, y+1));
        			visited.insert(make_pair(x, y+1));
        		}
        	}
        }

        return false;
    }

    bool findNumberIn2DArray2(vector<vector<int>>& matrix, int target) {
        // 剑指offer版本
    	if(matrix.empty() || matrix[0].empty() || target > matrix.back().back())
    		return false;

    	int i = matrix.size() - 1;
    	int j = 0;
    	while(j < matrix[0].size() && i >= 0){
    		if(matrix[i][j] == target){
    			return true;
    		}else if(matrix[i][j] > target){
    			i--;
    		}else{
    			j++;
    		}
    	}

    	return false;
    }
};

int main()
{
    std::vector<std::vector<int> > v = {
		{1,   4,  7, 11, 15},
		{2,   5,  8, 12, 19},
		{3,   6,  9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
    };

    cout << Solution().findNumberIn2DArray(v, 8) << endl;
    return 0;
}