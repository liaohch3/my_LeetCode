/*
* @Author: liaohch3
* @Date:   2020-04-15 18:23:25
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-15 20:19:07
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

void show(vector<vector<int> >& res){
    for(int i = 0; i < res.size(); i++){
    	for(int j = 0; j < res[0].size(); j++){
    		cout << res[i][j] << " ";
    	}
    	cout << endl;
    }
}

class Solution {
private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int> >& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dist(m, vector<int>(n));
        vector<vector<int> > seen(m, vector<int>(n));
        queue<pair<int, int> > q;
        // 将所有的 0 添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }

        // 广度优先搜索
        while (!q.empty()) {
            auto front = q.front();
            int i = front.first;
            int j = front.second;
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }

    return dist;
    }
};

int main()
{
    vector<vector<int> > matrix = {
    	{0, 0, 0},
    	{0, 1, 0},
    	{0, 0, 0},
    };
    vector<vector<int> > res = Solution().updateMatrix(matrix);
    show(res);
    return 0;
}