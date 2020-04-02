/*
* @Author: liaohch3
* @Date:   2020-04-01 15:38:38
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-01 16:29:47
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
    vector<int> maxDepthAfterSplit(string seq) {

    	if(seq.size() == 0)	return vector<int>();

    	int count = 0;
    	vector<int> res(seq.size());
    	for(int i = 0; i < seq.size(); i++){
    		char ch = seq[i];
    		if(ch == '('){
    			count++;
    			if(count % 2 == 0){
    				res[i] = 1;
    			}else{
    				res[i] = 0;
    			}
    		}else{
    			if(count % 2 == 0){
    				res[i] = 1;
    			}else{
    				res[i] = 0;
    			}
    			count--;
    		}
    	}
    	return res;
    }
};

int main()
{
    vector<int> res = Solution().maxDepthAfterSplit("()(())()");
    for(int item: res){cout << item << " ";}
    cout << endl;

    res = Solution().maxDepthAfterSplit("(()())");
    for(int item: res){cout << item << " ";}
    cout << endl;
    return 0;
}