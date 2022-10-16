class Solution {
public:
    int solve(int left, string &s, int K, vector<vector<int>> &dp) {
        int k = K;
        if(s.size() - left <= k)
            return 0;
        if(dp[left][k] >= 0)
            return dp[left][k];
        int res = k ? solve(left+1, s, k - 1, dp) : 10000, c = 1;
        for(int i = left + 1; i <= s.size(); i++) {
            res = min(res, solve(i, s, k, dp) + 1 + (c >= 100 ? 3 : (c >= 10 ? 2 : (c > 1 ? 1 :0))));
            if(i == s.size())
                break;
            if(s[i] == s[left])
                c++;
            else if(--k < 0)
                break;
        }
        return dp[left][K] = res;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(101, vector<int>(101, -1));
        return solve(0, s, k, dp);
    }
};