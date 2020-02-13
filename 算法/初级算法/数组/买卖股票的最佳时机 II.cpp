/*
* @Author: liaohch3
* @Date:   2020-02-09 12:00:16
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-09 12:50:54
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

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)	return 0;

        int sum = 0;
        for(int i = 0; i < prices.size() - 1; i++){
        	if(prices[i+1] > prices[i])
        		sum += prices[i+1] - prices[i];
        }

        return sum;
    }
};

int main()
{
	std::vector<int> prices = {7,1,5,3,6,4};
	cout << Solution().maxProfit(prices) << endl;
	
	prices = {1,2,3,4,5};
	cout << Solution().maxProfit(prices) << endl;
	
	prices = {7,6,4,3,1};
	cout << Solution().maxProfit(prices) << endl;

	return 0;
}