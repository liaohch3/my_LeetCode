#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        set<pair<int, int> > visited;
        queue<pair<int, int> > q;
        int color = image[sr][sc];
        vector<vector<int> > res = image;

        q.push(make_pair(sr, sc));
        visited.insert(make_pair(sr, sc));
        res[sr][sc] = newColor;

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                pair<int, int> pos = q.front();
                int x = pos.first;
                int y = pos.second;
                q.pop();

                if(x - 1 >= 0 && image[x-1][y] == color && visited.find(make_pair(x-1, y)) == visited.end())
                {
                    q.push(make_pair(x-1, y));
                    visited.insert(make_pair(x-1, y));
                    res[x-1][y] = newColor;
                }
                if(y - 1 >= 0 && image[x][y-1] == color && visited.find(make_pair(x, y-1)) == visited.end())
                {
                    q.push(make_pair(x, y-1));
                    visited.insert(make_pair(x, y-1));
                    res[x][y-1] = newColor;
                }
                if(x + 1 < image.size() && image[x+1][y] == color && visited.find(make_pair(x+1, y)) == visited.end())
                {
                    q.push(make_pair(x+1, y));
                    visited.insert(make_pair(x+1, y));
                    res[x+1][y] = newColor;
                }
                if(y + 1 < image[0].size() && image[x][y+1] == color && visited.find(make_pair(x, y+1)) == visited.end())
                {
                    q.push(make_pair(x, y+1));
                    visited.insert(make_pair(x, y+1));
                    res[x][y+1] = newColor;
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