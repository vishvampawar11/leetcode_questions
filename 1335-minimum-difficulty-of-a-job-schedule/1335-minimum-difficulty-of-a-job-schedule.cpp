class Solution {
public:
    int solve(int i, int d, int n, vector<int> &jd, vector<vector<int>> &dp) {
        if(d == 1)
            return *max_element(jd.begin()+i, jd.end());
        
        if(dp[i][d] != -1)
            return dp[i][d];

        int mx = INT_MIN;
        int ans = INT_MAX;
        
        for(int idx = i; idx<=n-d; idx++) {
            mx = max(mx, jd[idx]);
            ans = min(ans, mx + solve(idx+1, d-1, n, jd, dp));
        }
        return dp[i][d] = ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<vector<int>> dp(301, vector<int>(11, -1));
        return solve(0, d, n, jobDifficulty, dp);
    }
};