class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        vector<int> odd1, odd2, even1, even2;
        for(int i:nums) {
            if(i%2==0)
                even1.push_back(i);
            else
                odd1.push_back(i);
        }
         for(int i:target) {
            if(i%2==0)
                even2.push_back(i);
            else
                odd2.push_back(i);
        }
        for(int i=0; i<odd1.size(); i++) {
            if(odd1[i] < odd2[i])
                ans+=(odd2[i]-odd1[i])/2;
        }
        for(int i=0; i<even1.size() ;i++) {
            if(even1[i]<even2[i])
                ans+=(even2[i]-even1[i])/2;
        }
        return ans;
    }
};