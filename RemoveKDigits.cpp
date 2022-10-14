#include <iostream>
#include <stack>
#include <string>
using namespace std;
string removeKdigits(string num, int k)
{
    int n = num.size();
    stack<char> mystack;
    for (char c : num)
    {
        while (!mystack.empty() && k > 0 && mystack.top() > c)
        {
            mystack.pop();
            k--;
        }
        if (!mystack.empty() || c != '0')
        {
            mystack.push(c);
        }
    }
    //if we have budget we need to remove from our stack
    while (!mystack.empty() && k--)
        mystack.pop();
    if (mystack.empty())
        return "0";

    while (!mystack.empty())
    {
        num[n - 1] = mystack.top();
        mystack.pop();
        n--;
    }
    return num.substr(n);
}
int main(){
    string s = "10200";
    string out = removeKdigits(s, 1);
    cout << out;
}