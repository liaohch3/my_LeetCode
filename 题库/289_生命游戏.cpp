/*
* @Author: liaohch3
* @Date:   2020-04-02 23:05:19
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-02 23:15:03
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

	int count(vector<vector<int> >& board, int x, int y){
		int res = 0;
    	int m = board.size();
    	int n = board[0].size();

		if(x-1>=0 && board[x-1][y]==1)	res++;
		if(y-1>=0 && board[x][y-1]==1)	res++;
		if(x+1<m && board[x+1][y]==1)	res++;
		if(y+1<n && board[x][y+1]==1)	res++;
		if(x-1>=0 && y-1>=0 && board[x-1][y-1]==1)	res++;
		if(x+1<m && y-1>=0 && board[x+1][y-1]==1)	res++;
		if(x-1>=0 && y+1<n && board[x-1][y+1]==1)	res++;
		if(x+1<m && y+1<n && board[x+1][y+1]==1)	res++;

		return res;
	}

	bool next(vector<vector<int> >& board, int x, int y){
		int res = count(board, x, y);
		if(board[x][y] == 1){
			if(res < 2){
				return false;
			}else if(res <= 3){
				return true;
			}else{
				return false;
			}
		}else{
			if(res == 3){
				return true;
			}else{
				return false;
			}
		}
	}

public:
    void gameOfLife(vector<vector<int> >& board) {
    	if(board.empty() || board[0].empty())	
    		return ;

    	int m = board.size();
    	int n = board[0].size();
    	vector<vector<int> > res(board);
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			res[i][j] = next(board, i, j);
    		}
    	}

    	board = res;
    }
};

int main()
{
    
    return 0;
}