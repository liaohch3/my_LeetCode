#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 2)	return true;
        long long i = 1;
        long long j = num;
        while(i <= j){
        	long long mid = i + (j - i) / 2;
        	if(mid * mid == num)
        		return true;
        	if(mid * mid < num)
        		i = mid + 1;
        	else
        		j = mid - 1;
        }
        return false;
    }
};

int main()
{

	for(int i = 0; i < 17; i++){
		cout << i << " " << Solution().isPerfectSquare(i) << endl;
	}
	return 0;
}