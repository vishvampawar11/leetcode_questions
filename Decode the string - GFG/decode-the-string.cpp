//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        string ans;
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(s[i]==']') {
                string curr;
                while(st.top() != '[') {
                    curr.push_back(st.top());
                    st.pop();
                }
                st.pop();
                string num;
                while(!st.empty() && isdigit(st.top())) {
                    num.push_back(st.top());
                    st.pop();
                }
                reverse(num.begin(), num.end());
                reverse(curr.begin(), curr.end());
                int nm = stoi(num);
                string str;
                for(int i=0;i<nm;i++)
                    str+=curr;
                for(int i=0;i<str.size();i++)
                    st.push(str[i]);
            }
            else 
                st.push(s[i]);
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends