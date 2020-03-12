/*
* @Author: liaohch3
* @Date:   2020-03-12 18:12:10
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-12 18:36:20
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
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
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    	int one = 0;
    	int i = start;
    	while(i != destination){
    		one += distance[i];
    		i = (i + 1) % distance.size();
    	}

    	int two = 0;
    	int j = destination;
    	while(j != start){
    		two += distance[j];
    		j = (j + 1) % distance.size();
    	}

    	return min(one, two);
    }
};

int main()
{
    cout << (-1 % 3) << endl;
    return 0;
}