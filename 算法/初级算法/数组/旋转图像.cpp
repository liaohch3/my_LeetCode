/*
* @Author: liaohch3
* @Date:   2020-02-12 15:31:45
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-13 23:34:03
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

	void show(vector<vector<int> >& matrix){
		int n = matrix.size();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

    void rotate(vector<vector<int> >& matrix) {
    	int n = matrix.size();
    	if(n <= 1)	return;

    	for(int k = 0; k < n / 2; k++){
	        for(int i = 0; i < n - 1 - 2 * k; i++){
	        	int buffer = matrix[k][i+k];
	        	matrix[k][i+k] = matrix[n-1-i-k][k];
	        	matrix[n-1-i-k][k] = matrix[n-1-k][n-1-i-k];
	        	matrix[n-1-k][n-1-i-k] = matrix[i+k][n-1-k];
	        	matrix[i+k][n-1-k] = buffer;
	        }
    	}
    }
};

int main()
{
    // vector<vector<int> > matrix = {
    // 	{1,2,3},
    // 	{4,5,6},
    // 	{7,8,9}
    // };    
  //   vector<vector<int> > matrix = {
		// { 5, 1, 9,11},
		// { 2, 4, 8,10},
		// {13, 3, 6, 7},
		// {15,14,12,16}
  //   };
    vector<vector<int> > matrix = {
    	{1,2,3,4,5},
    	{6,7,8,9,10},    	
    	{11,12,13,14,15},
    	{16,17,18,19,20},    	
    	{21,22,23,24,25}
    };

    Solution().rotate(matrix);
    return 0;
}