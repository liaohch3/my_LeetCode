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
    int mySqrt(int x) {
        if(x == 0)  return 0;

        int i = 1;
        int j = x;
        while(i <= j){
            long long mid = i + (j - i) / 2;
            if(mid * mid <= x && (mid+1) * (mid+1) > x)
                return mid;
            else if(mid * mid > x)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return 1;
    }
};

int main()
{

    cout << Solution().mySqrt(2147395599) << endl;
    cout << Solution().mySqrt(4) << endl;

    return 0;
}