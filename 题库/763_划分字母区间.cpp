/*
* @Author: liaohch3
* @Date:   2020-03-11 18:22:05
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-03-11 22:10:37
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
    vector<int> partitionLabels(string S) {
    	if(S.size() <= 1)	return vector<int>(1, S.size());
    
    	vector<int> res;

    	int first[26] = {0};
    	int last[26] = {0};
    	memset(first, -1, 26*sizeof(int));
    	memset(last, -1, 26*sizeof(int));

    	for(int i = 0; i < S.size(); i++){
    		if(first[S[i]-'a'] == -1){
    			first[S[i]-'a'] = i;
    		}
    		last[S[i]-'a'] = i;
    	}

    	int now = 0;
    	int lastIndex = 0;
    	for(int i = 0; i < S.size(); i++){
    		lastIndex = max(lastIndex, last[S[i] - 'a']);
    		// printf("lastIndex: %d\n", lastIndex);
    		if(i == lastIndex){
    			res.push_back(lastIndex-now+1);
    			now = lastIndex + 1;
    			// printf("now: %d, lastIndex: %d\n", now, lastIndex);
    		}
    	}

    	// for(int i = 0; i < 26; i++){
    	// 	if(first[i] != -1){
    	// 		printf("%c %d %d\n", 'a'+i, first[i], last[i]);
    	// 	}
    	// }

    	return res;
    }
};

int main()
{
    vector<int> res = Solution().partitionLabels("ababcbacadefegdehijhklij");
    for(int item: res){
    	cout << item << endl;
    }

	// string str = "ababcbacadefegdehijhklij";
	// for(int i = 0; i < str.size(); i++){
	// 	cout << str[i] << " " << i << endl;
	// }

    return 0;
}