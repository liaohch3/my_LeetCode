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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hashMap;
        for(int i = 0; i < list1.size(); i++)
        	hashMap[list1[i]] = i;

        string bestRest = "";
        int minSum = 0x7fffffff;

        vector<string> res;

        for(int i = 0; i < list2.size(); i++){
        	if(hashMap.find(list2[i]) != hashMap.end()){
        		if(i + hashMap[list2[i]] < minSum){
        			minSum = i + hashMap[list2[i]];
        			bestRest = list2[i];
        			res.clear();
        			res.push_back(list2[i]);
        		}else if(i + hashMap[list2[i]] == minSum){
        			res.push_back(list2[i]);
        		}
        	}
        }

        return res;
    }
};

int main()
{
	return 0;
}