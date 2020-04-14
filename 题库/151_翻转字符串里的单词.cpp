/*
* @Author: liaohch3
* @Date:   2020-04-10 11:19:39
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-04-10 11:49:20
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
    	if(s.empty())	return "";

    	int now = 0;
    	int last = 0;
    	int start = -1;
    	stack<string> st;

    	for(int i = 0; i < s.size(); i++){
    		if(s[i] != ' '){
    			start = i;
    			break;
    		}
    	}

    	if(start == -1)	return "";

    	for(int i = start + 1; i < s.size(); i++){
    		if(s[i] == ' '){
    			if(i - start > 0){
					st.push(s.substr(start, i - start));
    			}
    			start = i + 1;
    		}
    	}

    	if(start != s.size()){
    		st.push(s.substr(start));
    	}

    	string res = st.top();
		st.pop();
    	while(!st.empty()){
    		res += " ";
    		res += st.top();
    		st.pop();
    	}

    	return res;
    }
};

int main()
{
    cout << Solution().reverseWords("the sky is blue") << endl;
    cout << Solution().reverseWords("  hello world!  ") << endl;
    cout << Solution().reverseWords("a good   example") << endl;
    // cout << Solution().reverseWords() << endl;
    // cout << Solution().reverseWords() << endl;
    // cout << Solution().reverseWords() << endl;
    return 0;
}