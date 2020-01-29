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
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashMap1;
        unordered_map<char, char> hashMap2;

        for(int i = 0; i < s.size(); i++){
        	if(hashMap2.find(t[i]) != hashMap2.end() && hashMap2[t[i]] != s[i])
        		return false;
        	else if(hashMap1.find(s[i]) != hashMap1.end() && hashMap1[s[i]] != t[i])
        		return false;
        	else if(hashMap2.find(t[i]) == hashMap2.end()){
        		hashMap1[s[i]] = t[i];
        		hashMap2[t[i]] = s[i];
        	}
        }
        return true;
    }
};

int main()
{
	return 0;
}