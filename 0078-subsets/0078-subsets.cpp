class Solution {
public:
    void solve(int i ,int n, vector<int>curr, vector<vector<int>> &ans, vector<int> &nums) {
        if(i==n) {
            ans.push_back(curr);
            return;
        }
        vector<int> curr1 = curr;
        curr1.push_back(nums[i]);
        solve(i+1, n, curr, ans, nums);
        solve(i+1, n, curr1, ans, nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums.size(), {}, ans, nums);
        return ans;
    }
};