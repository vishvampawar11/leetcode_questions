class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i=0, j=0, curr=0;
        while(j<n) {
            while(j<n && chars[i]==chars[j])
                j++;
            chars[curr++] = chars[i];
            if(j-i>1) {
                string str = (to_string(j-i));
                for(int k=0;k<str.size();k++)
                    chars[curr++] = str[k];
            }
            i=j;
        }
        
        return curr;
    }
};