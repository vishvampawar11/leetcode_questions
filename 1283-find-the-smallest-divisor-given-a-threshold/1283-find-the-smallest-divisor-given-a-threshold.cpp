class Solution {
public:
    int help(int num, vector<int> &nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
            ans+=ceil((float)nums[i]/(float)num);
        return ans;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        
        while(l<=r) {
            int mid = l + (r-l)/2;
            int ans = help(mid, nums);
            if(ans <= threshold)
                r = mid-1;
            else
                l = mid+1;
        }
        return l;
    }
};