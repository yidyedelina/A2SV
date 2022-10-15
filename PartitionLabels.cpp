#include <vector>
#include <iostream>
using namespace std;
vector<int> partitionLabels(string s)
{
    vector<int> lookUp(26, 0);
    //build last occurence
    for (int i = 0; i < s.size(); i++)
    {
        lookUp[s[i] - 'a'] = i;
    }
    vector<int> res;
    int r = 0, l = 0;
    //when i == r, push to the vector new occurence of 
    for (int i = 0; i < s.size(); i++)
    {
        r = max(r, lookUp[s[i] - 'a']);
        if (i == r)
        {
            res.push_back(r - l + 1);
            l = r + 1;
        }
    }
    return res;
}
