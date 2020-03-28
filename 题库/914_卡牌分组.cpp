/*
* @Author: liaohch3
* @Date:   2020-03-27 14:43:32
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-27 15:04:44
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
    bool hasGroupsSizeX(vector<int>& deck) {
    	if(deck.size() <= 1)	return false;

    	unordered_map<int, int> hashMap;
    	for(int item: deck){
    		hashMap[item]++;
    	}

    	int g = hashMap.begin()->second;
    	for(auto kv: hashMap){
    		g = __gcd(g, kv.second);
    		if(g == 1){
    			return false;
    		}
    	}

    	return true;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4,4,3,2,1};
    cout << Solution().hasGroupsSizeX(nums) << endl;
    nums = {1,1,1,2,2,2,3,3};
    cout << Solution().hasGroupsSizeX(nums) << endl;
    nums = {1};
    cout << Solution().hasGroupsSizeX(nums) << endl;
    nums = {1,1};
    cout << Solution().hasGroupsSizeX(nums) << endl;
    nums = {1,1,2,2,2,2};
    cout << Solution().hasGroupsSizeX(nums) << endl;
    return 0;
}