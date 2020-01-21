#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> snum;
        stack<string> sstr;
        int times = 0;
        string res = "";

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                times = times * 10 + s[i] - '0';
            }
            else if(s[i] == '[')
            {
                snum.push(times);
                times = 0;
                sstr.push(res);
                res = "";
            }
            else if(s[i] == ']')
            {
                int times_ = snum.top();
                snum.pop();
                string temp = "";
                for(int t=0; t<times_; t++)
                    temp += res;
                res = sstr.top() + temp;
                sstr.pop();
            }
            else
            {
                res += s[i];
            }
        }
        return res;
    }
};

// class Solution {
// public:
    
//     string decodeString(string s) {
//         if(s.size()==0)
//             return s;
//         stack<int>nums;
//         stack<string>strs;
//         string res="";
//         int len = s.size();
//         int num=0;
//         for(int i=0; i<len; i++)
//         {
//             if(s[i]>='0' && s[i]<='9')
//             {
//                 num = num*10 + s[i]-'0';
//             }
//             else if(s[i]=='[')
//             {
//                 nums.push(num);
//                 num=0;
//                 strs.push(res);
//                 res = "";
//             }
//             else if(s[i]==']')
//             {
//                 int times = nums.top();
//                 nums.pop();
//                 for(int t=0; t<times; t++)
//                     strs.top() += res;
//                 res = strs.top();
//                 strs.pop();
//             }
//             else
//             {
//                 res += s[i];
//             }
//         }
//         return res;
//     }
// };


int main()
{

    return 0;
}