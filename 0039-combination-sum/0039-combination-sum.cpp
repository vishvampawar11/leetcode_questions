class Solution {
public:
    void solve(int i, int t, int n, vector<int> &c, vector<int> curr, vector<vector<int>> &ans) {
        if(t==0) {
            ans.push_back(curr);
            return;
        }
        if(i==n || t<0)
            return;
        if(c[i]<=t) {
            vector<int> curr2 = curr;
            curr2.push_back(c[i]);
            solve(i, t-c[i], n, c, curr2, ans);
            solve(i+1, t, n, c, curr, ans);
        }
        else
            solve(i+1, t, n, c, curr, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        solve(0, target, n, candidates, {}, ans);
        return ans;
    }
};