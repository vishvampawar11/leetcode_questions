class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans;
        for(int col=0;col<n;col++) {
            int i=0, j = col;
            while(i<m) {
                if(grid[i][j]==1) {
                    if(j+1<n && grid[i][j+1]==1)
                        i++, j++;
                    else {
                        ans.push_back(-1);
                        break;
                    }
                }
                else {
                    if(j-1>=0 && grid[i][j-1]==-1)
                        i++, j--;
                    else {
                        ans.push_back(-1);
                        break;
                    }
                }
            }
            if(i==m)
                ans.push_back(j);
        }
        return ans;
    }
};