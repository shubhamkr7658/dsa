// class Solution {
// public:
//     int sumDecoded(vector<long long>& nums) {
//         int n=nums.size();
//         int mod=1e9+7;
//         int sum=0;
//         for(int i=0;i,n;i++){
//             int total=log10(nums[i])+1;
//             int width=1LL *nums[i]%10;
//             int d=floor(nums[i]/10);
//             int x=d/pow(total-width,10)%mod;
//             int y=d%pow(total-width,10)%mod;
//             sum+=pow(y,x);
//             sum=sum%mod;
//         }
//         return sum;
//     }
// };

class Solution {
public:
    long long mod = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long ans = 1;
        base %= mod;

        while (exp > 0) {
            if (exp % 2) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int width = nums[i] % 10;
            long long d = nums[i] / 10;
            int total = to_string(d).length();
            long long p = modPow(10, total - width);

            long long x = d / p;
            long long y = d % p;

            sum = (sum + modPow(x, y)) % mod;
        }

        return sum;
    }
};
