class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        int n = nums.size(), i = 0, j = 0;
        
        while(j<n) {
            m[nums[j]]++;
            if(m[nums[j]] > 1) return true;
            if(j-i+1 <= k)
                j++;
            else {
                m[nums[i]]--;
                i++;
                j++;
            }
        }
        
        return false;
    }
};