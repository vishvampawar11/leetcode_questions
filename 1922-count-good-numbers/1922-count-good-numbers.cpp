class Solution {
public:
    int m = 1e9+7;
    
    long long pow(long long a, long long b) {
        if(b==0)
            return 1;
        long long ans = pow(a, b/2);
        if(b&1) 
            return (a*(ans*ans)%m)%m;    
        return (ans*ans)%m;
    }
    
    int countGoodNumbers(long long n) {
        if(n&1)
            return (pow(4, n/2)*pow(5, n/2+1))%m;
        return (pow(4, n/2)*pow(5, n/2))%m;
    }
};