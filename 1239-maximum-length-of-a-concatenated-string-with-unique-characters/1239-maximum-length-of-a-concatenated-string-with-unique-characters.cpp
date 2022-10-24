class Solution {
public:
    
    // recursive function to check all possible subsequences
    int solve(int i, int msk, int n, vector<int> &masks) {
        if(i==n) 
            return __builtin_popcount(msk);
        
        // if two strings doesn't have common elements we have a choice to select ith string
        if((masks[i] & msk) == 0)
            return max(solve(i+1, (masks[i] | msk), n, masks), solve(i+1, msk, n, masks));
        // if they have common elements we can't select ith string
        else
            return solve(i+1, msk, n, masks);
    }
    
    int maxLength(vector<string>& arr) {       
        // removing all strings which contain duplicates
        int i = 0;
        while(i<arr.size()) {
            vector<int> cnt(26);
            bool flag = false;
            for(int j=0;j<arr[i].size();j++) {
                cnt[arr[i][j]-'a']++;
                if(cnt[arr[i][j]-'a'] > 1) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                arr.erase(arr.begin()+i);
            }
            else
                i++;
        }
        
        // forming bitmasks for all strings
        vector<int> masks;
        for(int i=0;i<arr.size();i++) {
            int msk = 0;
            for(int j=0;j<arr[i].size();j++)
                msk |= (1 << (arr[i][j] - 'a'));
            masks.push_back(msk);
        }
        
        return solve(0, 0, arr.size(), masks);
    }
};