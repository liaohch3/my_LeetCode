/*
* @Author: liaohch3
* @Date:   2020-03-30 16:28:07
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-31 10:37:05
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
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> hashMap;
        for(int& item: arr){
        	hashMap[item]++;
        }

        int maxOne = -1;
        for(auto& kv: hashMap){
        	if(kv.first == kv.second){
        		maxOne = max(maxOne, kv.first);
        	}
        }

        return maxOne;
    }
};

int main()
{
    vector<int> arr = {7,7,7,7,7,7,7};
    cout << Solution().findLucky(arr) << endl;
    return 0;
}