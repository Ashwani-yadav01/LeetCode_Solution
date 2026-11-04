class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        // Impossible to form k disjoint subarrays of length x
        if (1LL * x * k > n) return -1;

        vector<long long> cost(n - x + 1);
        
        // Track rolling medians and the sum of both halves
        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                int val = *left.rbegin();
                left.erase(prev(left.end()));
                leftSum -= val;
                right.insert(val);
                rightSum += val;
            }
            while (right.size() > left.size()) {
                int val = *right.begin();
                right.erase(right.begin());
                rightSum -= val;
                left.insert(val);
                leftSum += val;
            }
        };

        for (int i = 0; i < n; i++) {
            // Add incoming element to sliding window
            if (left.empty() || nums[i] <= *left.rbegin()) {
                left.insert(nums[i]);
                leftSum += nums[i];
            } else {
                right.insert(nums[i]);
                rightSum += nums[i];
            }
            balance();

            // Remove outgoing element from sliding window
            if (i >= x) {
                int out_val = nums[i - x];
                auto it = left.find(out_val);
                if (it != left.end()) {
                    left.erase(it);
                    leftSum -= out_val;
                } else {
                    it = right.find(out_val);
                    right.erase(it);
                    rightSum -= out_val;
                }
                balance();
            }

            // Calculate minimum cost efficiently in O(1)
            if (i >= x - 1) {
                long long median = *left.rbegin();
                cost[i - x + 1] = rightSum - leftSum + median * (x % 2);
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<long long> prev_dp(n + 1, 0), curr_dp(n + 1, INF);

        for (int t = 1; t <= k; t++) {
            fill(curr_dp.begin(), curr_dp.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr_dp[i] = curr_dp[i - 1]; // Skip the current element

                if (i >= x && prev_dp[i - x] != INF) {
                    curr_dp[i] = min(curr_dp[i], prev_dp[i - x] + cost[i - x]);
                }
            }
            prev_dp.swap(curr_dp);
        }

        return prev_dp[n];
    }
};// this is not written by me