#include <string>
using namespace std;
int maxVowels(string s, int k)
{
    int maxVowel = 0;
    int curVowel = 0;
    int left = 0, right = 0;
    while (right < s.size())
    {
        if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u')
        {
            curVowel++;
        }
        if (right - left + 1 == k)
        {
            maxVowel = max(maxVowel, curVowel);
            if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u')
            {
                curVowel--;
            }
            left++;
        }
        right++;
    }
    return maxVowel;
}