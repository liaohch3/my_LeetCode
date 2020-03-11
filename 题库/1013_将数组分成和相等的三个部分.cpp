/*
* @Author: liaohch3
* @Date:   2020-03-11 16:14:17
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-11 18:20:25
*/

#include <iostream>
#include <stack>
#include <string>
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
    bool canThreePartsEqualSum(vector<int>& A) {
    	
    	int sum = 0;
    	for(int item: A){
    		sum += item;
    	}

    	if(sum % 3 != 0){
    		return false;
    	}

    	int one = sum / 3;
    	int two = sum / 3 * 2;

    	int i = 0;
    	sum = 0;
    	while(i < A.size()){
    		sum += A[i];
    		if(sum == one){
    			break;
    		}
    		++i;
    	}

    	if(sum != one || i >= A.size() - 2){
    		return false;
    	}

    	i++;
    	while(i < A.size()){
    		sum += A[i];
    		if(sum == two){
    			break;
    		}
    		++i;
    	}

    	if(sum != two || i == A.size() - 1){
    		return false;
    	}

    	return true;
    }
};

int main()
{
    vector<int> A = {0,2,1,-6,6,-7,9,1,2,0,1};
    cout << Solution().canThreePartsEqualSum(A) << endl;
    
	A = {0,2,1,-6,6,7,9,-1,2,0,1};
    cout << Solution().canThreePartsEqualSum(A) << endl;
    
	A = {3,3,6,5,-2,2,5,1,-9,4};
    cout << Solution().canThreePartsEqualSum(A) << endl;
 
	A = {1,-1,1,-1};
    cout << Solution().canThreePartsEqualSum(A) << endl;
    


    return 0;
}