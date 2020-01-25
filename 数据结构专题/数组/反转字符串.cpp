#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
    	if(s.empty() || s.size() == 1)	return;
        int i = 0; 
        int j = s.size() - 1;

        while(i < j)
        {
        	char temp = s[i];
        	s[i] = s[j];
        	s[j] = temp;
        	i++;
        	j--;
        }

    }
};

int main()
{

	return 0;
}