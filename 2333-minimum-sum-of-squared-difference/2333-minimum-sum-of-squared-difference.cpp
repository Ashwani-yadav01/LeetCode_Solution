
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<int> freq(100001, 0);

        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            mx = max(mx, d);
        }

        for (int d = mx; d > 0 && k > 0; d--) {
            long long count = freq[d];
            long long use = min(k, count);

            freq[d] -= use;
            freq[d - 1] += use;
            k -= use;
        }

        long long ans = 0;

        for (int d = 1; d <= 100000; d++) {
            ans += 1LL * d * d * freq[d];
        }

        return ans;
    }
};
//this is noot written by me this is written by ai 