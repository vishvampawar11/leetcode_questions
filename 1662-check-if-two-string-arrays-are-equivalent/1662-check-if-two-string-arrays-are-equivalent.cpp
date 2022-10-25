class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a, b;
        for(string c : word1)
            a+=c;
        for(string c : word2)
            b+=c;
        return a==b;
    }
};