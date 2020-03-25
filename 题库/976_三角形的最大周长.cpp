/*
* @Author: liaohch3
* @Date:   2020-03-23 18:38:59
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-23 23:46:12
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
    int largestPerimeter(vector<int>& A) {
    	sort(A.begin(), A.end());
        for(int i = A.size() - 3; i >= 0; i--){
            if(A[i] + A[i+1] > A[i+2]){
                return A[i] + A[i+1] + A[i+2];
            }
        }

        return 0;
    }
};

int main()
{
    
    return 0;
}