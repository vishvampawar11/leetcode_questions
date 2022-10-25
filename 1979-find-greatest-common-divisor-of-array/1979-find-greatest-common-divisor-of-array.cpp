class Solution {
public:
    int gcd(int a, int b) {
        return b==0 ? a : gcd(b, a%b);
    }
    
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        return gcd(mn, mx);
    }
};