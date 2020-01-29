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
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, int> hashMap;

        for(int i = 0; i < strs.size(); i++){
        	string temp = strs[i];
        	sort(temp.begin(), temp.end());
        	if(hashMap.find(temp) == hashMap.end()){
        		vector<string> vec(1, strs[i]);
        		hashMap[temp] = res.size();
        		res.push_back(vec);
        	}else{
        		res[hashMap[temp]].push_back(strs[i]);
        	}
        }
        return res;
    }
};

int main()
{
	return 0;
}