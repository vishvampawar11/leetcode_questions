class Solution {
private:
    bool check(map<char, int> &m1, map<char, int> &m2) {
        for (auto it : m2) {
            char c = it.first;
            if (m1[c] < m2[c])
                return false;
        }
        return true;
    }
    
public:
    string minWindow(string s, string t) {
        map<char, int> m1, m2;
        for (char c : t)
            m2[c]++;
        int i = 0, j = 0, n = s.size(), len = 1e7;
        string ans;
        while (j < n) {
            m1[s[j]]++;
            while (check(m1, m2) && i < n) {
                if (j - i + 1 < len) {
                    len = j - i + 1;
                    ans = s.substr(i, j - i + 1);
                }
                m1[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};