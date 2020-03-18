/*
* @Author: liaohch3
* @Date:   2020-03-17 11:10:45
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-17 11:13:50
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
    	unordered_map<char, int> hashMap;
    	for(char ch: chars){
    		hashMap[ch]++;
    	}

    	int res = 0;
    	for(string word: words){
    		unordered_map<char, int> tempMap(hashMap);

    		bool flag = true;
    		for(char ch: word){
    			if(tempMap[ch] == 0){
    				flag = false;
    				break;
    			}else{
    				tempMap[ch]--;
    			}
    		}

    		if(flag){
    			res += word.size();
    		}
    	}

    	return res;
    }
};

int main()
{
    
    return 0;
}