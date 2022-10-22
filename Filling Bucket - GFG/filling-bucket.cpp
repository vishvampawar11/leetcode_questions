//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int m = 1e8;
    
    int solve(int N, vector<long> &dp) {
        if(N<0)
            return 0;
        if(N==0)
            return 1;
        if(dp[N] != -1)
            return dp[N];
        if(N>=2)
            return dp[N] = (solve(N-2, dp)%m + solve(N-1, dp)%m)%m;
        else
            return dp[N] = solve(N-1, dp)%m;
    }
  
    int fillingBucket(int N) {
        // code here
        vector<long> dp(1e5+1, -1);
        return solve(N, dp)%m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends