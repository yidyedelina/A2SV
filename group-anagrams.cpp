class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> dict;
        for (auto str: strs){
            string temp = str;
            sort(str.begin(), str.end());
            dict[str].emplace_back(move(temp));
        }
        vector<vector<string>> anagrams;
        for (auto words: dict){
            anagrams.emplace_back(move(words.second));
        }
        return anagrams;
    }
};