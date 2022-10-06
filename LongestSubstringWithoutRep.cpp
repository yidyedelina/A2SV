#include <vector>
#include <string>
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