//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    vector<int> ans;
    
    void solve(vector<int> &pre, int n) {
        if(n==0)
            return;
        if(n==1) {
            ans.push_back(pre[0]);
            return;
        }
        int root = pre[0];
        vector<int> left, right;
        for(int i=1;i<pre.size();i++) {
            if(pre[i]<root)
                left.push_back(pre[i]);
            else
                right.push_back(pre[i]);
        }
        solve(left, left.size());
        solve(right, right.size());
    }
    
  public:
    vector<int> leafNodes(int arr[], int n) {
        // code here
        vector<int> pre;
        for(int i=0;i<n;i++)
            pre.push_back(arr[i]);
        solve(pre, n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends