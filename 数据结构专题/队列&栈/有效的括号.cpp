#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0)
            return true;

        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')')
            {
                if(st.empty() || st.top() != '(')
                    return false;
                else
                    st.pop();
            }
            else if(s[i] == ']')
            {
                if(st.empty() || st.top() != '[')
                    return false;
                else
                    st.pop();
            }
            else if(s[i] == '}')
            {
                if(st.empty() || st.top() != '{')
                    return false;
                else
                    st.pop();
            }
        }

        return st.empty();
    }
};

int main()
{

    return 0;
}