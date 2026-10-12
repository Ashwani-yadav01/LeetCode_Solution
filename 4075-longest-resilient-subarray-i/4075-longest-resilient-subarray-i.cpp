class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            int rem = nums[i] % k;

            for (int j = i; j < n; j++) {
                if (nums[j] % k != rem)
                    break;

                sum += nums[j];

                if (sum % k == rem)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};