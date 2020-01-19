#include <iostream>
#include <vector>
#include <set>
// #include <pair>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {

    	if(grid.size() == 0)
    		return 0;

    	int width = grid[0].size();
    	int height = grid.size();
        queue<int> q;
        int num = 0;

        for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				if(grid[i][j] == '1')
				{
					grid[i][j] = '0';
					q.push(i*width+j);
					num ++;

					while(!q.empty())
					{
						int size = q.size();

						for(int k = 0; k < size; k++)
						{

							int front = q.front();
							q.pop();
							int x = front / width;
							int y = front % width;
							if(x - 1 >= 0 && grid[x-1][y] == '1')
							{
								q.push((x-1)*width+y);
								grid[x-1][y] = '0';
							}
							if(y - 1 >= 0 && grid[x][y-1] == '1')
							{
								q.push(x*width+y-1);
								grid[x][y-1] = '0';
							}
							if(x + 1 < grid.size() && grid[x+1][y] == '1')
							{
								q.push((x+1)*width+y);
								grid[x+1][y] = '0';
							}
							if(y + 1 < grid[0].size() && grid[x][y+1] == '1')
							{
								q.push(x*width+y+1);
								grid[x][y+1] = '0';
							}
						}
					}
				}
			}
		 } 
		 return num;
    }
};


// typedef pair<int, int> Pos;
// class Solution {
// public:
// 	int numIslands(vector<vector<char> >& grid) {
		
// 		vector<vector<int> > grid;
// 		for(int i = 0; i < grid.size(); i++)
// 		{
// 			vector<int> temp;
// 			for(int j = 0; j < grid[0].size(); j++)
// 			{
// 				temp.push_back(grid[i][j] - '0');
// 			}
// 			grid.push_back(temp);
// 		 } 
		
// 		set<Pos> visited;
// 		queue<Pos> q;
// 		int num = 0;

// 		while(1){
// 			bool flag = false;
// 			for(int i = 0; i < grid.size(); i++)
// 			{
// 				for(int j = 0; j < grid[0].size(); j++)
// 				{
// 					if(grid[i][j] == 1)
// 					{
// 						Pos p(i, j);
// 						q.push(p);
// 						visited.insert(p);
// 						grid[i][j] = 0;
// 						flag = true;
// 						num++;
// 						break;
// 					}
// 				}
// 			}

// 			if(!flag)
// 				return num;

// 			while(!q.empty())
// 			{
// 				int size = q.size();
// 				for(int i = 0; i < size; i++)
// 				{
// 					Pos p = q.front();
// 					q.pop();
// 					int x = p.first;
// 					int y = p.second;
// 					if(x - 1 >= 0 && grid[x-1][y] == 1 && visited.count(Pos(x-1, y)) == 0)
// 					{
// 						q.push(Pos(x-1, y));
// 						visited.insert(Pos(x-1, y));
// 						grid[x-1][y] = 0;
// 					}
// 					if(y - 1 >= 0 && grid[x][y-1] == 1 && visited.count(Pos(x, y-1)) == 0)
// 					{
// 						q.push(Pos(x, y-1));
// 						visited.insert(Pos(x, y-1));
// 						grid[x][y-1] = 0;
// 					}
// 					if(x + 1 < grid.size() && grid[x+1][y] == 1 && visited.count(Pos(x+1, y)) == 0)
// 					{
// 						q.push(Pos(x+1, y));
// 						visited.insert(Pos(x+1, y));
// 						grid[x+1][y] = 0;
// 					}
// 					if(y + 1 < grid[0].size() && grid[x][y+1] == 1 && visited.count(Pos(x, y+1)) == 0)
// 					{
// 						q.push(Pos(x, y+1));
// 						visited.insert(Pos(x, y+1));
// 						grid[x][y+1] = 0;
// 					}

// 				}

// 			}
// 		}
// 	}
// };

int main(){
	return 0;
}
