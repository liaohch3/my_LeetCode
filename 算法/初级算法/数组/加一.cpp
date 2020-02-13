/*
* @Author: liaohch3
* @Date:   2020-02-09 14:51:16
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-09 15:18:43
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
    vector<int> plusOne(vector<int>& digits) {

    	vector<int> res(digits);

        for(int i = res.size() - 1; i >= 0; i--){
        	if(res[i] == 9){
        		res[i] = 0;
        	}
        	else{
        		res[i]++;
        		break;
        	}
        }
        if(res[0] == 0){
        	res.insert(res.begin(), 1, 1);
        }
        return res;
    }
};


int main()
{	
	std::vector<int> v = {0};
	std::vector<int> res = Solution().plusOne(v);
	for(int i:res){
		cout << i << " ";
	}
	cout << endl;

	return 0;
}