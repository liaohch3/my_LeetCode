/*
* @Author: liaohch3
* @Date:   2020-03-28 16:12:45
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-28 23:11:31
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
    int minimumLengthEncoding(vector<string>& words) {
    	return minimumLengthEncoding2(words);
    }
    int minimumLengthEncoding2(vector<string>& words) {
    	// 反转排序法 https://leetcode-cn.com/problems/short-encoding-of-words/solution/wu-xu-zi-dian-shu-qing-qing-yi-fan-zhuan-jie-guo-j/

    	for(string & word : words){
    		reverse(word.begin(), word.end());
    	}
    	sort(words.begin(), words.end());

    	int res = words.back().size() + 1;
    	for(int i = 0; i < words.size() - 1; i++){
    		int size = words[i].size();
    		if(words[i+1].substr(0, size) != words[i]){
    			res += words[i].size() + 1;
    		}
    	}	

    	return res;
    }
    int minimumLengthEncoding1(vector<string>& words) {
    	// 暴力法
    	unordered_set<string> hashSet;
    	for(string item: words){
    		hashSet.insert(item);
    	}

    	for(string item: hashSet){
    		for(int i = 1; i < item.size(); i++){
    			if(hashSet.count(item.substr(i)) == 1){
    				hashSet.erase(item.substr(i));
    			}
    		}
    	}

    	int res = 0;
    	for(string item: hashSet){
    		res += item.size() + 1;
    	}

    	return res;
    }
};

int main()
{
    vector<int> v = {1,2,3};
    for(int item: v){
    	cout << item << " ";
    }
    cout << endl; 

    v.push_back(0);
    for(int item: v){
    	cout << item << " ";
    }
    cout << endl;
    return 0;
}