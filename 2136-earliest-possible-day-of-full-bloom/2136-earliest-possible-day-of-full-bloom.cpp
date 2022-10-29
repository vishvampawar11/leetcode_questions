class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        int n = pt.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++) 
            v.push_back({gt[i],pt[i]});
        sort(v.begin(),v.end(), greater<vector<int>>());
        int days = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            days+=v[i][1];
            ans=max(ans, days + v[i][0]);
        }
        return ans;
    }
};