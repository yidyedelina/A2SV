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
        if(ns.find(s[i]) == ns.end()){
            ns[s[i]] = 1;
        }else{
            ns[s[i]] += 1;
        }
        if (np.find(p[i]) == np.end())
        {
            np[p[i]] = 1;
        }
        else
        {
            np[p[i]] += 1;
        }
    }
    right = p.size();
    while (right <= s.size())
    {
        if(ns == np){
            nangram.push_back(left);
        }
        if(right == s.size())
            break;
        if(ns.find(s[right]) == ns.end()){
            ns[s[right]] = 1;
        }else{
            ns[s[right]] += 1;
        }
        ns[s[left]] -= 1;
        if(ns[s[left]] == 0){
            ns.erase(s[left]);
        }
        left++;
        right++;
    }
    return nangram;
}