/*
* @Author: liaohch3
* @Date:   2020-03-11 22:12:58
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-11 22:53:53
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

void show(vector<vector<string> >& res){
    for(int i = 0; i < res.size(); i++){
    	for(int j = 0; j < res[i].size(); j++){
    		cout << res[i][j] << endl;
    	}
    	cout << endl;
    }
}


class Solution {
public:

	bool check(const vector<string>& board, int row, int col){
		int n = board.size();

		for(int i = 0; i < row; i++){
			if(board[i][col] == 'Q'){
				return false;
			}
		}

		for(int i = 0; i < col; i++){
			if(board[row][i] == 'Q'){
				return false;
			}
		}

		int i = row - 1;
		int j = col - 1;
		while(i >= 0 && j >= 0){
			if(board[i][j] == 'Q'){
				return false;
			}
			i--;
			j--;
		}

		i = row - 1;
		j = col + 1;
		while(i < board.size() && j < board[0].size()){
			if(board[i][j] == 'Q'){
				return false;
			}
			i--;
			j++;
		}

		return true;
	}

	void dfs(vector<vector<string> >& res, vector<string>& board, int row){
		for(int i = 0; i < board.size(); i++){
			board[row][i] = 'Q';
			if(check(board, row, i)){
				if(row < board.size() - 1){
					dfs(res, board, row+1);
				}
				else{
					res.push_back(board);
				}
			}

			board[row][i] = '.';
		}
	}

    vector<vector<string> > solveNQueens(int n) {
    	vector<string> board(n, string(n, '.'));
    	vector<vector<string> > res;
    	dfs(res, board, 0);
    	return res;
    }
};

int main()
{
    vector<vector<string> > res = Solution().solveNQueens(4);
    show(res);

    return 0;
}