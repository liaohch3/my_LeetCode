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
        vector<int> res(m * n, 0);
        int pos = 0;
        // int level = 0;
        int levelMax = m > n ? n / 2 : m / 2;

        for(int level = 0; level < levelMax; level++)
        {
            for(int i = 0; i < n - 1 - 2*level; i++)
            {
                res[pos] = matrix[level][level+i];
                pos++;
            }
            for(int i = 0; i < m - 1 - 2*level; i++)
            {
                res[pos] = matrix[level+i][n-1-level];
                pos++;
            }
            for(int i = 0; i < n - 1 - 2*level; i++)
            {
                res[pos] = matrix[m-1-level][n - 1 - level - i];
                pos++;
            }
            for(int i = 0; i < m - 1 - 2*level; i++)
            {
                res[pos] = matrix[m-1-i-level][level];
                pos++;
            }
        }

        if(m == n && m % 2 == 1)
        {
            res[pos] = matrix[levelMax][levelMax];
        }
        else if(m < n && m % 2 == 1)
        {
            for(int i = 0; i < n - 2 * levelMax; i++)
            {
                res[pos] = matrix[levelMax][levelMax + i];
                pos++;
            }
        }
        else if(m > n && n % 2 == 1)
        {
            for(int i = 0; i < m - 2 * levelMax; i++)
            {
                res[pos] = matrix[levelMax + i][levelMax];
                pos++;
            }
        }

        return res;
    }
};

int main()
{
    // vector<vector<int> > vec = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12}
    // };
    // vector<vector<int> > vec = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9},
    //     {10, 11, 12}
    // };
    vector<vector<int> > vec = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    // vector<vector<int> > vec = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12}
    // };

    vector<int> res = Solution().spiralOrder(vec);
    
    for(int i = 0 ; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}