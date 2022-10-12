class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int l = 0, r = 0, n = nums.size();
        while(r<n-1) {
            int farthest = 0;
            for(int i=l;i<=r;i++)
                farthest = max(farthest, i+nums[i]);
            l = r+1;
            r = farthest;
            ans++;
        }
        return ans;
    }
};