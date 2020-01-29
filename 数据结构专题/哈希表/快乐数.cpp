#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hashSet;
        
        while(n != 1){
        	if(hashSet.count(n) == 0)
        		hashSet.insert(n);
        	else
        		break;

        	int temp = n;
        	n = 0;
        	while(temp){
        		n += (temp % 10) * (temp % 10);
        		temp /= 10;
        	}
        }

        return n == 1;

    }
};

int main()
{
	return 0;
}