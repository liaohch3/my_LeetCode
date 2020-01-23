#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;

        if(numRows == 0)
        	return res;

        res.push_back(vector<int>(1, 1));
        if(numRows == 1)
        	return res;

        res.push_back(vector<int>(2, 1));
        if(numRows == 2)
        	return res;

        for(int i = 2; i < numRows; i++)
        {
        	vector<int> row(i+1, 1);
        	vector<int> lastRow = res.back();

        	for(int j = 0; j < i - 1; j++)
        		row[j+1] = lastRow[j] + lastRow[j+1];

        	res.push_back(row);
        }
        return res;
    }
};

int main()
{

	return 0;
}