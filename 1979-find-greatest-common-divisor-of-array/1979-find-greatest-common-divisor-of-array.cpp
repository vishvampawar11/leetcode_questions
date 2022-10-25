class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [mn, mx] = minmax_element(begin(nums), end(nums));
        return gcd(*mn, *mx);
    }
};