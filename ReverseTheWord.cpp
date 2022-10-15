#include <iostream>
#include <string>
using namespace std;
string reverseWords(string s)
{
    string ns = "";
    string sp = "";
    int left = 0, right = 0;
    while (right < s.size())
    {
        if (s[right] == ' ')
        {
            if (right != left)
            {
                ns = sp + ns;
                left = right + 1;
            }
            else
                left++;
            sp = "";
        }
        sp = sp + s[right];
        right++;
    }
    if(right != left){
        ns = s.substr(left, (right - left + 1)) +  " " + ns;
    }
    return ns;
}

int main(){
    string s = "  the sky    is blue";
    string r = reverseWords(s);
    cout << r << endl;
}