#include <string>
#include <stack>
using namespace std;
string reverseParentheses(string s)
{
    stack<char> st;
    for (char &i : s)
    {
        if (i == ')')
        {
            string temp = "";
            while (st.top() != '(')
            {
                temp += st.top();
                st.pop();
            }
            st.pop();
            for (char &j : temp)
            {
                st.push(j);
            }
        }
        else
        {
            st.push(i);
        }
    }
    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}