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
			res.push_back(s.substr(blank1 + 1, blank2 - blank1 - 1));
			blank1 = blank2;
			blank2 = s.find(" ", blank1+1);
		}

		if(blank1 != s.size() - 1)
			res.push_back(s.substr(blank1 + 1));

		return res;
	}

	void reverseWord(string& word)
	{
		int i = 0;
		int j = word.size() - 1;
		while(i < j)
		{
			char temp = word[i];
			word[i] = word[j];
			word[j] = temp;
			i++;
			j--;
		}
	}

    string reverseWords(string s) {
        if(s.empty())	
        	return s;

        vector<string> words = getVector(s);

        // cout << "===========================" << endl;
        // for(int i = 0; i < words.size(); i++)
        // 	cout << words[i] << " ";
        // cout << endl;
        // cout << "===========================" << endl;


        string res = "";
        if(words.empty()) return res;

        for(int i = 0; i < words.size() - 1; i++)
        {
        	reverseWord(words[i]);
        	res += words[i];
        	res += " ";
        }
        reverseWord(words.back());
        res += words.back();
        return res;
    }
};

int main()
{
	cout << Solution().reverseWords("hehhhhhhe") << endl;
	// cout << Solution().reverseWords("Let's take LeetCode contest") << endl;

	return 0;
}