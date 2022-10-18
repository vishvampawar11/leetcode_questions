class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int l=2;l<=n;l++) {
            int len = ans.size();
            int i=0, j=0;
            string newans;
            while(j<len) {
                if(ans[i]==ans[j])
                    j++;
                else {
                    newans.push_back(j-i+'0');
                    newans.push_back(ans[i]);
                    i=j;
                }
            }
            newans.push_back(j-i+'0');
            newans.push_back(ans[i]);
            ans = newans;
        }
        return ans;
    }
};
