#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:

	set<int> visited;

    bool canVisitAllRooms(vector<vector<int> >& rooms) {
    	visited.insert(0);
    	DFS(rooms, 0);
    	return visited.size() == rooms.size();
    }

	void DFS(vector<vector<int> >& rooms, int x)
	{
		for(int i = 0; i < rooms[x].size(); i++)
		{
			if(visited.find(rooms[x][i]) == visited.end())
			{
				visited.insert(rooms[x][i]);
				DFS(rooms, rooms[x][i]);
			}
		}
	}

};

int main()
{

	return 0;
}