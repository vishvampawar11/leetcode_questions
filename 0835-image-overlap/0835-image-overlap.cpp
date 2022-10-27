class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> p1;
        vector<pair<int, int>> p2;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(img1[i][j] == 1)
                    p1.push_back({i, j});
                if(img2[i][j] == 1)
                    p2.push_back({i, j});
            }
        }
        
        int ans = 0;
        map<pair<int, int>, int> m;
        for(auto it : p1) {
            int a = it.first, b = it.second;
            for(auto it1 : p2) {
                int c = it1.first, d = it1.second;
                m[{c-a, d-b}]++;
                ans = max(ans, m[{c-a, d-b}]);
            }
        }
        
        return ans;
    }
};