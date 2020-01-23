#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a == "") return b;
        if(b == "") return a;

        // 弄成a长b短
        if(a.size() < b.size())
        {
            string temp = a;
            a = b;
            b = temp; 
        }

        // 补齐b
        b.insert(b.begin(), a.size()-b.size(), '0');

        string res = a;
        int flag = 0;
        int len = a.size();
        for(int i = 0; i < len; i++)
        {
            if(a[len-1-i] == '1' && b[len-1-i] == '1' && flag == 0)
            {
                res[len-1-i] = '0';
                flag = 1;
            }
            else if(a[len-1-i] == '1' && b[len-1-i] == '1' && flag == 1)
            {
                res[len-1-i] = '1';
                flag = 1;
            }
            else if(a[len-1-i] == '0' && b[len-1-i] == '0' && flag == 0)
            {
                res[len-1-i] = '0';
                flag = 0;
            }
            else if(a[len-1-i] == '0' && b[len-1-i] == '0' && flag == 1)
            {
                res[len-1-i] = '1';
                flag = 0;
            }
            else if(a[len-1-i] == '0' && b[len-1-i] == '1' && flag == 0)
            {
                res[len-1-i] = '1';
                flag = 0;
            }
            else if(a[len-1-i] == '0' && b[len-1-i] == '1' && flag == 1)
            {
                res[len-1-i] = '0';
                flag = 1;
            }
            else if(a[len-1-i] == '1' && b[len-1-i] == '0' && flag == 0)
            {
                res[len-1-i] = '1';
                flag = 0;
            }
            else if(a[len-1-i] == '1' && b[len-1-i] == '0' && flag == 1)
            {
                res[len-1-i] = '0';
                flag = 1;
            }
        }
        if(flag == 1)
            res.insert(res.begin(), 1, '1');
        return res;
    }
};

int main()
{
    cout << Solution().addBinary(string("11"), string("111")) << endl;
    return 0;
}