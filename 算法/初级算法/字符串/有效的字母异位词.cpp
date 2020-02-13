/*
* @Author: liaohch3
* @Date:   2020-02-13 23:52:48
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-14 00:10:11
*/

#include <iostream>
#include <stack>
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
    bool isAnagram(string s, string t) {
		int alpha[26] = {0};
		for(char ch: s){
			alpha[ch-'a']++;
		}
		for(char ch: t){
			alpha[ch-'a']--;
		}
		for(int i = 0; i < 26; i++){
			if(alpha[i] != 0){
				return false;
			}
		}
		return true;
    }
};

int main()
{
    
    return 0;
}