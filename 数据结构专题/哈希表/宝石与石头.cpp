#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> hashSet(J.begin(), J.end());
        int res = 0;
        for(int i = 0; i < S.size(); i++)
        	if(hashSet.count(S[i]) == 1)
        		res++;
        return res;
    }
};

int main()
{
	return 0;
}