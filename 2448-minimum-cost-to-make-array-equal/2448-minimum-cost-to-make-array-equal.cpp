class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, int>> v;
        long long n = nums.size(), sum = 0, tot = 0, median = 0, ans = 0;
        for(int i=0;i<n;i++) {
            v.push_back({nums[i], cost[i]});
            sum+=cost[i];   
        }
        sort(v.begin(), v.end());
        
        int i = 0;
        while(tot<=sum/2 && i<n) {
            tot+=v[i].second;
            median = v[i].first;
            i++;
        }
        for(auto it : v)
            ans += (abs(median-it.first) * it.second);
        return ans;
    }
};