#include <vector>
#include <string>
#include <iostream>
using namespace std;


int lengthOfLongestSubstring(string s)
{
    int curMax = 0, maxLen = 0;
    int left = 0, right = 0;
    string curStr = "";
    for (int i = 0; i < s.size(); i++){
        if(curStr.find(s[i]) == string::npos){
            curStr += s[i];
            right++;
            continue;
        }
        maxLen = maxLen > curStr.size() ? maxLen : curStr.size();
        while(curStr.find(s[i]) != string::npos){
            curStr.erase(curStr.begin());
            left++;
        }
        curStr += s[i];
        left++, right++;
    }
    return maxLen > curStr.size() ? maxLen : curStr.size();
}

int lengthOfLonegestSubstring1(string s){
    int curMax = 0, maxLen = 0;
    int right = 0, left = 0;
    string curStr = "";
    while(right < s.size()){
        if(curStr.find(s[right]) == string::npos){
            curMax = right - left + 1;
            maxLen = max(curMax, maxLen);
        }else {
            while (curStr.find(s[right]) != string::npos)
            {
                curStr.erase(curStr.begin());
                left++;
            }
        }
        curStr += s[right];
        right++;
    }
    return maxLen;
}
int main(){
    string b = "abcacdb";
    int a = lengthOfLonegestSubstring1(b);
    cout << a << endl;
}