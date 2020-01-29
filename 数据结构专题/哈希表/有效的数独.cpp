#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {

        for(int i = 0; i < 9; i++){
	        unordered_set<char> hashSet1;
	        unordered_set<char> hashSet2;
	        unordered_set<char> hashSet3;
        	for(int j = 0; j < 9; j++){
        		if(board[i][j] != '.' && hashSet1.count(board[i][j]) == 1)
        			return false;
        		else if(board[i][j] != '.')
	        		hashSet1.insert(board[i][j]);

        		if(board[j][i] != '.' && hashSet2.count(board[j][i]) == 1)
        			return false;
        		else if(board[j][i] != '.')
        			hashSet2.insert(board[j][i]);

        		int row = (i / 3) * 3 + (j / 3); 
        		int col = (i % 3) * 3 + (j % 3); 
        		if(board[row][col] != '.' && hashSet3.count(board[row][col]) == 1)
        			return false;
        		else if(board[row][col] != '.')
        			hashSet3.insert(board[row][col]);
        	}
        }

        return true;
    }
};

int main()
{
	return 0;
}