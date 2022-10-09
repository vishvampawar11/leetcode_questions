class Solution {
public:
    int solve(int i, int j, string w1, string w2, int n1, int n2, vector<vector<int>> &dp) {
        if(i==n1 && j==n2) return 0;
        if(i==n1) return n2 - j;
        if(j==n2) return n1 - i;
        if(dp[i][j] != -1) return dp[i][j];
        if(w1[i] == w2[j]) return dp[i][j] = solve(i+1, j+1, w1, w2, n1, n2, dp);
        
        return dp[i][j] =  1 + min({solve(i, j+1, w1, w2, n1, n2, dp), solve(i+1, j, w1, w2, n1, n2, dp), solve(i+1, j+1, w1, w2, n1, n2, dp)});
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        // return solve(0, 0, word1, word2, n1, n2, dp);
        
        for(int i=0;i<=n1;i++) {
            for(int j=0;j<=n2;j++) {
                if(i==0 && j==0)
                    dp[i][j] = 0;
                else if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        }
        
        return dp[n1][n2];
    }
};