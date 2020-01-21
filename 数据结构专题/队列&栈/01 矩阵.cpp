#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:

    int BFS(vector<vector<int> >& matrix, int sx, int sy)
    {
        if(matrix[sx][sy] == 0)
            return 0;
        
        set<pair<int, int> > visited;
        queue<pair<int, int> > q;

        q.push(make_pair(sx, sy));
        visited.insert(make_pair(sx, sy));

        int dist = 0;

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                pair<int, int> pos = q.front();
                int x = pos.first;
                int y = pos.second;
                q.pop();

                if(matrix[x][y] == 0)
                    return dist;

                if(x - 1 >= 0 && visited.find(make_pair(x-1, y)) == visited.end())
                {
                    q.push(make_pair(x-1, y));
                    visited.insert(make_pair(x-1, y));
                }
                if(y - 1 >= 0 && visited.find(make_pair(x, y-1)) == visited.end())
                {
                    q.push(make_pair(x, y-1));
                    visited.insert(make_pair(x, y-1));
                }
                if(x + 1 < matrix.size() && visited.find(make_pair(x+1, y)) == visited.end())
                {
                    q.push(make_pair(x+1, y));
                    visited.insert(make_pair(x+1, y));
                }
                if(y + 1 < matrix[0].size() && visited.find(make_pair(x, y+1)) == visited.end())
                {
                    q.push(make_pair(x, y+1));
                    visited.insert(make_pair(x, y+1));
                }
            }
            dist ++;
        }
        return dist;
    }

    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        vector<vector<int> > res = matrix;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                res[i][j] = BFS(matrix, i, j);
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}