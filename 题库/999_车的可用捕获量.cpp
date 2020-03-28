/*
* @Author: liaohch3
* @Date:   2020-03-26 17:29:33
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-26 17:37:27
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
	inline bool legal(const char& ch){
		return ch == '.' || ch == 'p';
	}
public:
    int numRookCaptures(vector<vector<char> >& board) {
    	int n = board.size();
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < n; j++){
    			if(board[i][j] == 'R'){
    				int res = 0;

    				int k = 1;
    				while(i - k >= 0 && legal(board[i-k][j])){
    					if(board[i-k][j] == 'p'){
    						res ++;
    						break;
    					}
    					k++;
    				}
					k = 1;
    				while(j - k >= 0 && legal(board[i][j-k])){
    					if(board[i][j-k] == 'p'){
    						res ++;
    						break;
    					}
    					k++;
    				}
					k = 1;
    				while(i + k < n && legal(board[i+k][j])){
    					if(board[i+k][j] == 'p'){
    						res ++;
    						break;
    					}
    					k++;
    				}
					k = 1;
    				while(j + k < n && legal(board[i][j+k])){
    					if(board[i][j+k] == 'p'){
    						res ++;
    						break;
    					}
    					k++;
    				}

    				return res;
    			}
    		}
    	}

    	return 0;
    }
};

int main()
{
    
    return 0;
}