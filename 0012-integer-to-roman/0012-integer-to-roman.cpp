class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> romans = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int i=12;  
        int d;
        string ans;
        while(num > 0) {
            d = num/nums[i];
            num %= nums[i];
            while(d--)
                ans+=romans[i];
            i--;
        }
        return ans;   
    }
};