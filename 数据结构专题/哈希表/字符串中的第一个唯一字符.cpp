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
    int firstUniqChar(string s) {
        return firstUniqChar2(s);
    }

    int firstUniqChar1(string s) {
		// 哈希映射法，很蠢很慢
		// 学了哈希就忘记老本了。。。
		// 数组能解决，没必要用哈希

        unordered_map<char, int> hashMap;
        for(int i = 0; i < s.size(); i++){
        	if(hashMap.find(s[i]) == hashMap.end()){
        		hashMap[s[i]] = i;
        	}else{
        		hashMap[s[i]] = -1;
        	}
        }

        int minIndex = s.size() + 1;
        // for(unordered_map<char, int>::iterator it = hashMap.begin(); it != hashMap.end(); it++){
        for(auto it = hashMap.begin(); it != hashMap.end(); it++){
        	if(it->second != -1 && it->second < minIndex)
        		minIndex = it->second;
        }

        return minIndex == s.size() + 1 ? -1 : minIndex;
    }

    int firstUniqChar2(string s) {
        int alpha[26] = {0};
        for(int i = 0; i < s.size(); i++)
        	alpha[s[i] - 'a']++;

        for(int i = 0; i < s.size(); i++)
        	if(alpha[s[i] - 'a'] == 1)
        		return i;

        return -1;
    }
};

int main()
{
	return 0;
}