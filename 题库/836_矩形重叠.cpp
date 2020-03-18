/*
* @Author: liaohch3
* @Date:   2020-03-16 12:14:41
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-16 12:26:00
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
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    	return max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]) && max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);
    }
};

int main()
{
    
    return 0;
}