class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=0, k=0, n=nums.size();
        while(j<n) {
            if(nums[i]==nums[j])
                j++;
            else {
                nums[k++] = nums[i];
                i=j;
            }
        }
        nums[k] = nums[i];
        return k+1;
    }
};