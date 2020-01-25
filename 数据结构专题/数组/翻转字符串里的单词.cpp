#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> getVector(string s)
	{
		vector<string> res;

		int blank1 = -1;
		int blank2 = s.find(" ");

		while(blank2 != -1)
		{
			if(blank2 - blank1 != 1)
			{
				res.push_back(s.substr(blank1 + 1, blank2 - blank1 - 1));
			}
			blank1 = blank2;
			blank2 = s.find(" ", blank1+1);
		}

		if(blank1 != s.size() - 1)
			res.push_back(s.substr(blank1 + 1));

		return res;
	}


    string reverseWords(string s) {
        if(s.empty() || s.find(" ") == -1)	
        	return s;

        vector<string> words = getVector(s);

        // for(int i = 0; i < words.size(); i++)
        // 	cout << words[i] << " ";
        // cout << endl;

        string res = "";
        if(words.empty()) return res;

        for(int i = words.size() - 1; i > 0; i--)
        {
        	res += words[i];
        	res += " ";
        }
        res += words[0];
        return res;
    }
};

int main()
{
	cout << Solution().reverseWords("the sky is blue") << endl;
	cout << Solution().reverseWords("  hello world!  ") << endl;
	cout << Solution().reverseWords("a good   example") << endl;
	return 0;
}