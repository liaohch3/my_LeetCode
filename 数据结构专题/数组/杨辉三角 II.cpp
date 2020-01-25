#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex <= 1) return vector<int>(rowIndex+1, 1);
        vector<int> first(2, 1);
        for(int row = 2; row <= rowIndex; row++)
        {
            vector<int> now(row+1, 1);
            for(int i = 0; i < row - 1; i++)
                now[i+1] = first[i] + first[i+1];
            first.assign(now.begin(), now.end());
        }
        return first;
    }
};

int main()
{

    return 0;
}