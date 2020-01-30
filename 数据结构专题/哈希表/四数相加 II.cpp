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
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hashMap;

        for(int i = 0; i < A.size(); i++)
        	for(int j = 0; j < B.size(); j++)
        		hashMap[A[i]+B[j]]++;

        int res = 0;
        for(int i = 0; i < 	C.size(); i++)
        	for(int j = 0; j < D.size(); j++)
        		res += hashMap[-C[i]-D[j]];

        return res;
    }
};

int main()
{
	return 0;
}