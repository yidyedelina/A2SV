#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> findAnagrams(string s, string p)
{
    vector<int> nangram;
    unordered_map<char, int> ns;
    unordered_map<char, int> np;
    if(p.size() > s.size())
        return nangram;
    int left = 0, right = 0;
    for (int i = 0; i < p.size(); i++){
        ns[s[i]]++;
        np[p[i]]++;
    }
    right = p.size();
    while (right <= s.size())
    {
        if(ns == np){
            nangram.push_back(left);
        }
        if(right == s.size())
            break;
        ns[s[right]]++;
        ns[s[left]]--;
        if (ns[s[left]] == 0)
        {
            ns.erase(s[left]);
        }
        left++;
        right++;
    }
    return nangram;
}