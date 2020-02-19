/*
* @Author: liaohch3
* @Date:   2020-02-19 15:57:50
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-19 16:18:49
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
    int minArray(vector<int>& numbers) {
        if(numbers.empty())		return -1;
        if(numbers.size() == 1)	return numbers[0];
    
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j){
        	while(i < j && i < numbers.size() - 1 && numbers[i+1] == numbers[i])	i++;
        	while(i < j && j > 0 && numbers[j-1] == numbers[j])	j--;
        	if(i < j){
	        	if(numbers[i] < numbers[j]){
	        		return numbers[i];
	        	}else{
		        	int mid = i + (j - i) / 2;
		        	if(numbers[mid] >= numbers[i]){
		        		i = mid + 1;
		        	}else{
		        		j = mid;
		        	}
	        	}
        	}
        }

        return numbers[i];
    }
};

int main()
{
    std::vector<int> v = {3,4,5,1,2,3};
    cout << Solution().minArray(v) << endl;
    return 0;
}