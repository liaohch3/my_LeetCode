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
    double myPow(double x, int n) {
        long long longN = n;
        if(longN == 0)  return 1;
        if(longN == 1)  return x;

        if(longN < 0){
            x = 1 / x; 
            longN *= -1;
        }

        double temp = 1.0;
        while(longN != 1){
            if(longN % 2 ==0){
                x *= x;
                longN /= 2;
            }else{
                temp *= x;
                longN--;
                x *= x;
                longN /= 2;
            }
        }

        return temp * x;
    }
};

int main()
{

    cout << Solution().myPow(2, -2) << endl;

    return 0;
}