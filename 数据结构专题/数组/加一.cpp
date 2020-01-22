#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[0] == 0)
        	return vector<int>(1, 1);

        vector<int> res(digits);
        for(int i = res.size() - 1; i >= 0; i--)
        {
        	res[i]++;
        	if(res[i] == 10)
        	{
        		res[i] = 0;
        	}
        	else
        	{
        		return res;
        	}
        }
        if(res[0] == 0)
        {
        	res.insert(res.begin(), 1, 1);
        }
        return res;
    }
};

int main()
{

	return 0;
}