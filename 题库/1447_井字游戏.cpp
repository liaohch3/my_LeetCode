/*
* @Author: liaohchN
* @Date:   2020-0N-10 15:4N:40
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-10 16:05:54
*/

#include <iostream>
#include <stack>
#include <string>
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
    string tictactoe(vector<string>& board) {
    	int N = board.size();

    	if(N == 1){
    		if(board[0][0] == ' '){
    			return "Pending";
    		}else{
    			return board[0];
    		}
    	}

    	for(int i = 0; i < N; i++){
    		for(int j = 0; j < N - 1; j++){
    			if(board[i][j] != board[i][j+1]){
    				break;
    			}
    			if(j == N - 2){
    				if(board[i][0] == 'X'){
	    				return "X";
	    			}else if(board[i][0] == 'O'){
	    				return "O";
	    			}
    			}
    		}
    		for(int j = 0; j < N - 1; j++){
    			if(board[j][i] != board[j+1][i]){
    				break;
    			}
    			if(j == N - 2){
    				if(board[0][i] == 'X'){
	    				return "X";
	    			}else if(board[0][i] == 'O'){
	    				return "O";
	    			}
    			}
    		}
    	}

    	for(int i = 0; i < N; i++){
    		if(board[0][0] != board[i][i]){
    			break;
    		}
    		if(i == N - 1){
				if(board[0][0] == 'X'){
					return "X";
				}else if(board[0][0] == 'O'){
					return "O";
				}
    		}
    	}
    	for(int i = 0; i < N; i++){
    		if(board[N-1][0] != board[N-1-i][i]){
    			break;
    		}
    		if(i == N - 1){
				if(board[N-1][0] == 'X'){
					return "X";
				}else if(board[N-1][0] == 'O'){
					return "O";
				}
    		}
    	}

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(board[i][j] == ' '){
					return "Pending";
				}
			}
		}

		return "Draw";
    }
};

int main()
{
    std::vector<string> v = {"O X"," XO","X O"};
    cout << Solution().tictactoe(v) << endl;
    v = {"OOX","XXO","OXO"};
    cout << Solution().tictactoe(v) << endl;
    v = {"OOX","XXO","OX "};
    cout << Solution().tictactoe(v) << endl;
    v = {"O"};
    cout << Solution().tictactoe(v) << endl;
    return 0;
}