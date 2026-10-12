class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> bits(31, 0);

        for (int x : nums) {
            for (int i = 0; i < 31; i++) {
                if (x & (1LL << i)) {
                    bits[i]++;
                }
            }
        }

        long long ans = 0;

        while (k--) {
            long long val = 0;

            for (int i = 30; i >= 0; i--) {
                if (bits[i] > 0) {
                    val |= (1LL << i);
                    bits[i]--;
                }
            }

            ans = (ans + val * val) % MOD;
        }

        return ans;
    }
};