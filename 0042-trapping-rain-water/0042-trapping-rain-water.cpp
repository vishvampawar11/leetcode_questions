class Solution {
public:
    int findAns(vector<int> &ht) {
        int n = ht.size(), ans = 0;;
        stack<pair<int, int>> st;
        st.push({ht[n-1], n-1});
        for(int i=n-2;i>=0;i--) {
            while(!st.empty() && st.top().first < ht[i])
                st.pop();
            if(!st.empty()) {
                int nxt = st.top().first;
                int nxtidx = st.top().second;
                ans += (nxtidx-i-1)*ht[i];
                for(int j=i+1;j<nxtidx;j++) {
                    ans-=ht[j];   
                    ht[j] = ht[i];
                }
            }
            st.push({ht[i], i});
        }
        return ans;
    }
    
    int trap(vector<int>& ht) {
        int ans1 = findAns(ht);
        vector<int> ht1 = ht;
        reverse(ht1.begin(), ht1.end());
        int ans2 = findAns(ht1);
        return ans1 + ans2;
    }
};