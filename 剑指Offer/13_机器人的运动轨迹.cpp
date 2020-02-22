/*
* @Author: liaohch3
* @Date:   2020-02-22 10:52:39
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-22 11:48:30
*/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

class Solution {
public:

	int decompose(int num){
		int res = 0;
		while(num){
			res += num % 10;
			num /= 10;
		}
		return res;
	}

	bool vaild(int x, int y, int k){
		return (decompose(x) + decompose(y)) <= k;
	}

    int movingCount(int m, int n, int k) {
    	queue<int> q;
    	q.push(0);
    	vector<bool> visited(m*n, 0);
    	visited[0] = true;
    	int res = 0;

    	while(!q.empty()){
    		int size = q.size();
    		for(int i = 0; i < size; ++i){
    			int now = q.front();
    			q.pop();
				int x = now / n;
				int y = now % n;
				++res;

				if(x+1<m && visited[(x+1)*n+y]==false && vaild(x+1, y, k)){
					visited[(x+1)*n+y] = true;
					q.push((x+1)*n+y);
				}
				if(y+1<n && visited[(x)*n+y+1]==false && vaild(x, y+1, k)){
					visited[(x)*n+y+1] = true;
					q.push((x)*n+y+1);
				}
				if(x-1>=0 && visited[(x-1)*n+y]==false && vaild(x-1, y, k)){
					visited[(x-1)*n+y] = true;
					q.push((x-1)*n+y);
				}
				if(y-1>=0 && visited[(x)*n+y-1]==false && vaild(x, y-1, k)){
					visited[(x)*n+y-1] = true;
					q.push((x)*n+y-1);
				}
    		}
    	}

    	return res;
    }
};

int main()
{
    // cout << Solution().movingCount(2, 3, 1) << endl;
    // cout << Solution().movingCount(3, 1, 0) << endl;
    cout << Solution().movingCount(38, 15, 9) << endl; // 135
    return 0;
}