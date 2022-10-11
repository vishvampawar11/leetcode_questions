class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = 1;
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;
                if(len==3) return true;
            }
            else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return false;
    }
};