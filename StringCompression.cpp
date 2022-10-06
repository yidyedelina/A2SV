#include <vector>
#include <string>
#include <iostream>
using namespace std;

int compress(vector<char> &chars)
{
    int count = 0;
    int left = 0;
    int right = 0;
    while (left < chars.size())
    {
        while (right < chars.size() && chars[left] == chars[right])
        {
            right++;
        }
        chars[count++] = chars[left];
        if (right - left > 1)
        {
            string s = to_string(right - left);
            for (char c : s)
            {
                chars[count++] = c;
            }
        }
        left = right;
    }
    return count;
}

int main(){
    vector<char> a{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int b = compress(a);
    cout << b;
    return 0;
}