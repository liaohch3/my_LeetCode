/*
* @Author: liaohch3
* @Date:   2020-03-18 16:56:10
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-18 17:44:41
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
	vector<int> wSum;
	int sum;
public:
    Solution(vector<int>& w) {
    	wSum.resize(w.size());
    	sum = 0;
    	for(int i = 0; i < w.size(); i++){
    		sum += w[i];
    		wSum[i] = sum;
    	}
    }

    int test(int a){
    	int i = 0;
    	int j = wSum.size();

    	while(i < j){
    		int mid = i + (j - i) / 2;
    		if(wSum[mid] > a){
    			j = mid;
    		}else if(wSum[mid] == a){
    			return mid;
    		}else{
    			i = mid + 1;
    		}
    	}
    	return i;
    }
    
    int pickIndex() {
    	int choice = rand() % sum + 1;
    	int i = 0;
    	int j = wSum.size();

    	while(i < j){
    		int mid = (i + j) / 2;
    		if(wSum[mid] > choice){
    			j = mid;
    		}else if(wSum[mid] == choice){
    			return mid;
    		}else{
    			i = mid + 1;
    		}
    	}
    	return i;
    }
};

int main()
{
	vector<int> v = {1,3,1};
    Solution s(v);
    for(int i = 1; i <= 5; i++){
    	cout << i << " " << s.test(i) << endl;
    }
    return 0;
}