/*
* @Author: liaohch3
* @Date:   2020-02-13 23:50:33
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-13 23:52:39
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
    int firstUniqChar(string s) {
        unordered_map<char, int> hashMap;
        for(char ch: s){
            hashMap[ch]++;
        }
        for(int i = 0; i < s.size(); i++){
            if(hashMap[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}