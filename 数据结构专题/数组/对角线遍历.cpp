#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
    	if(matrix.empty())
    		return vector<int>();
        int x = 0;
        int y = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int pos = 0;
        vector<int> res(m * n, 0);
        bool ur = true;

        while(pos != m * n)
        {
        	res[pos] = matrix[x][y];
        	pos++;
        	if(ur)
        	{
        		if(x - 1 >= 0 && y + 1 < n)
        		{
	        		x--;
	        		y++;
        		}
        		else
        		{
        			ur = false;
        			if(y == n - 1)
        			{
        				x++;
        			}
        			else if(x == 0)
        			{
        				y++;
        			}
        		}
        	}
        	else
        	{
        		if(x + 1 < m && y - 1 >= 0)
        		{
        			x++;
        			y--;
        		}
        		else
        		{
        			ur = true;
        			if(x == m - 1)
        			{
        				y++;
        			}
        			else if(y == 0)
        			{
        				x++;
        			}
        		}
        	}
        }
        return res;
    }
};

int main()
{

	return 0;
}