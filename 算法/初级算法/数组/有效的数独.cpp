/*
* @Author: liaohch3
* @Date:   2020-02-12 15:21:31
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-12 15:30:44
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
    bool isValidSudoku(vector<vector<char> >& board) {
        
        for(int i = 0; i < 9; i++){
            unordered_set<char> row;
            unordered_set<char> col;
            unordered_set<char> block;

            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(row.count(board[i][j])){
                        return false;
                    }else{
                        row.insert(board[i][j]);
                    }
                }

                if(board[j][i] != '.'){
                    if(col.count(board[j][i])){
                        return false;
                    }else{
                        col.insert(board[j][i]);
                    }
                }    
                
                int a = (i / 3) * 3 + j / 3;
                int b = (i % 3) * 3 + j % 3;
                if(board[a][b] != '.'){
                    if(block.count(board[a][b])){
                        return false;
                    }else{
                        block.insert(board[a][b]);
                    }
                }           
            }
        }

        return true;
    }
};


int main()
{
    
    return 0;
}