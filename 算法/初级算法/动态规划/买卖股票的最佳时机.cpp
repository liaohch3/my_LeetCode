/*
* @Author: liaohch3
* @Date:   2020-02-15 11:43:15
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-15 12:07:46
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
    int maxProfit(vector<int>& prices) {
		int minPrice = INT_MAX;
		int maxNowProfit = 0;
        for(int i = 0; i < prices.size(); i++){
        	if(prices[i] < minPrice){
        		minPrice = prices[i];
        	}
        	if(prices[i] - minPrice > maxNowProfit){
        		maxNowProfit = prices[i] - minPrice;
        	}
        }
        return maxNowProfit;
    }
};

int main()
{
    
    return 0;
}