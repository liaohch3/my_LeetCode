#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    bool check(string & str){
        if(str.size() == 0)
            return false;
        if(str.size() == 1 && str[0] == '-')
            return false;
        int start = 0;
        if(str[0] == '-')
            start = 1;
        for(int i = start; i < str.size(); i++)
            if(str[i] < '0' || str[i] > '9')
                return false;
        return true;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(check(tokens[i]))
                s.push(stoi(tokens[i], 0, 10));
            else
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if(tokens[i] == "+")
                    s.push(a + b);
                else if(tokens[i] == "-")
                    s.push(a - b);
                else if(tokens[i] == "*")
                    s.push(a * b);
                else if(tokens[i] == "/")
                    s.push(a / b);
            }
        }
        return s.top();
    }
};

int main()
{
    return 0;
}