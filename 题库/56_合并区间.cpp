/*
* @Author: liaohch3
* @Date:   2020-04-16 09:49:47
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-16 10:23:28
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

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {

    	if(intervals.empty())	return vector<vector<int> >();

        sort(intervals.begin(), intervals.end());

        vector<vector<int> > res;
        int start = -1;
        int end = -1;

        for(int i = 0; i < intervals.size(); i++){
        	if(intervals[i][0] <= end){
        		end = max(intervals[i][1], end);
        		res.back()[1] = end;
        	}else{
        		res.push_back(intervals[i]);
        		start = intervals[i][0];
        		end = intervals[i][1];
        	}
        }

        return res;
    }
};

int main()
{
    
    return 0;
}