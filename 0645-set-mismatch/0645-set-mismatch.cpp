class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long sumN=0, sumArr=0, sumNSq = 0, sumArrSq = 0, n = nums.size();
        for(int i=0;i<n;i++) {
            sumArr+=nums[i];
            sumArrSq+=nums[i]*nums[i];
        }
        sumN = n*(n+1)/2;
        sumNSq = n*(n+1)*(2*n+1)/6;
        long x = sumN-sumArr, y = (sumNSq - sumArrSq)/(sumN - sumArr);
        return {(int)((y-x)/2), (int)((y+x)/2)};
    }
};