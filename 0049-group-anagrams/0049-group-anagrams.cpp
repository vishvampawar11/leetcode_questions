class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> ans;
        for(string &s : strs) {
            string s1 = s;
            sort(s1.begin(), s1.end());
            m[s1].push_back(s);
        }
        for(auto &it : m)
            ans.push_back(it.second);
        return ans;
    }
};