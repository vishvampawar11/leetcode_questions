//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    string maxSum(string w,char x[], int b[],int n) {
        // code here        
        int currMax = 0;
        pair<int, int> maxSoFar = {0, 0};
        map<char, int>m;
        string ans;
        for(int i=0;i<n;i++)
            m[x[i]] = b[i];
        
        for(int i=0;i<w.size();i++) {
            int val = w[i];
            if(m.find(w[i]) != m.end())
                val = m[w[i]];
            currMax+=val;
            if(maxSoFar.first < currMax) {
                maxSoFar.first = max(currMax, maxSoFar.first);
                ans = w.substr(maxSoFar.second, i-maxSoFar.second+1);
            }
            if(currMax<0) {
                currMax = 0;
                maxSoFar.second = i+1;
            }
        }
        if(ans.empty()) {
            int mx = INT_MIN;
            char x;
            for(auto it : m) {
                if(it.second > mx) {
                    mx = it.second;
                    x = it.first;
                }
            }
            ans.push_back(x);
        }
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
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends