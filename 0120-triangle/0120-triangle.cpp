class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>> &dp) {
        if(i==n-1)
            return triangle[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = triangle[i][j] + min(solve(i+1, j, n, triangle, dp), solve(i+1, j+1, n, triangle, dp));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(0, 0, n, triangle, dp);
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum+=triangle[i][0];
            dp[i][0] = sum;
        }
        sum = 0;
        for(int i=0;i<n;i++) {
            sum+=triangle[i][i];
            dp[i][i] = sum;
        }
        for(int i=2;i<n;i++) {
            for(int j=1;j<i;j++)
                dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++) 
            ans = min(ans, dp[n-1][i]);
        return ans;
    }
};      