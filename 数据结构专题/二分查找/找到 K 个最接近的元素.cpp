#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0, hi = arr.size() - k;
        while (lo < hi) {
            int mid = lo + (hi - lo >> 1);
            if (x - arr[mid] > arr[mid + k] - x ) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};

int main()
{
	cout << abs(-1) << endl;

	return 0;
}