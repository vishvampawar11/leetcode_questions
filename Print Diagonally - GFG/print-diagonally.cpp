//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A) {
		// Your code goes here
		vector<int> ans;
		int i=0, j=0;
		while(j<n) {
		    int i1=i, j1=j;
		    while(j1>=0)
		        ans.push_back(A[i1++][j1--]);
		    j++;
		}
		j--;
		i++;
		while(i<n) {
		    int i1 = i, j1 = j;
		    while(i1<n)
		        ans.push_back(A[i1++][j1--]);
		    i++;
		}
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends