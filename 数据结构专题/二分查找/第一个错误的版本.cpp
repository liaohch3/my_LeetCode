#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long i = 1;
        long long j = n + 1;

        while(i < j){
            long long mid = i + (j - i) / 2;
            bool res = isBadVersion(mid);
            if(res)
                j = mid;
            else
                i = mid + 1;
        }

        return i;
    }
};



int main()
{



    return 0;
}