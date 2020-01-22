#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        
    	if(matrix.empty())
    		return vector<int>();

        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0, y = 0;
        vector<int> res(m*n, 0);
        int pos = 0;
        int level = 0;

        while(pos != m*n)
        {
        	for(int i = 0; i < n - 1 - level; i++)
        	{
        		res[pos] = matrix[level][i];
        		pos++;
        	}
        	for(int i = 0; i < m - 1 - level; i++)
        	{
        		res[pos] = matrix[n-1][i];
        		pos++;
        	}
        	for(int i = 0; i < n - 1 - level; i++)
        	{
        		res[pos] = matrix[m-1][n - i];
        		pos++;
        	}
        	for(int i = 0; i < n - 1 - level; i++)
        	{
        		res[pos] = matrix[level][i];
        		pos++;
        	}

        }
        return res;
    }
};

int main()
{

	return 0;
}