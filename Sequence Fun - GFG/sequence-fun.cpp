//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int mod = 1e9+7;
	public:
		int NthTerm(int n){
		    // Code  here
		    if(n==1) return 2;
		    long long x = 2, prev = 2, curr;
		    for(int i=0;i<n-1;i++) {
		        curr = (((prev%mod)*(x%mod))%mod + 1)%mod;
		        prev = curr;
                x++;
		    }
		    return curr;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends