class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1) return "";
        for(int i=0;i<n;i++) {
            if(palindrome[i] != 'a' && (i!=n/2 || n&1 != 1)) {
                palindrome[i] = 'a';
                return palindrome;
            } 
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};