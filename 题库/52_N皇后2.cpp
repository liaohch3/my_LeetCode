/*
* @Author: liaohch3
* @Date:   2020-03-11 22:12:58
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-11 22:59:01
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

	bool check(const vector<string>& board, int row, int col){
		int n = board.size();

		for(int i = 0; i < row; ++i){
			if(board[i][col] == 'Q'){
				return false;
			}
		}

		for(int i = 0; i < col; ++i){
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
			--i;
			j--;
		}

		i = row - 1;
		j = col + 1;
		while(i < board.size() && j < board[0].size()){
			if(board[i][j] == 'Q'){
				return false;
			}
			--i;
			++j;
		}

		return true;
	}

	void dfs(int& res, vector<string>& board, int row){
		for(int i = 0; i < board.size(); ++i){
			board[row][i] = 'Q';
			if(check(board, row, i)){
				if(row < board.size() - 1){
					dfs(res, board, row+1);
				}
				else{
					res++;
				}
			}

			board[row][i] = '.';
		}
	}

    int totalNQueens(int n) {
    	vector<string> board(n, string(n, '.'));
    	int res = 0;
    	dfs(res, board, 0);
    	return res;
    }
};

int main()
{
    cout << Solution().totalNQueens(4) << endl;

    return 0;
}