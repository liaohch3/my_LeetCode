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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(auto num : nums)
        	hashMap[num]++;

        priority_queue<pair<int, int> > q;
        for(auto it : hashMap)
        	q.push(make_pair(it.second, it.first));

        vector<int> res(k);
        for(int i = 0; i < k; i++){
        	res[i] = q.top().second;
        	q.pop();
        }

        return res;
    }
};

int main()
{
	return 0;
}