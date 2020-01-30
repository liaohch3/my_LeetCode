#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int i = 1;
        int j = n;
        while(i <= j){
        	int mid = i + (j - i) / 2;
        	int res = guess(mid);
        	if(res == 0)
        		return mid;
        	else if(res == 1)
        		i = mid + 1;
        	else
        		j = mid - 1;
        }
        return 1;
    }
};

int main()
{
	return 0;
}