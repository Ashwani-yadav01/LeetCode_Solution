class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, pair<int, int>>> vec;
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back({digitSum(nums[i]), {nums[i], i}});
        }

        sort(vec.begin(), vec.end());
        int swaps = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (vis[i] || vec[i].second.second == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = true;
                j = vec[j].second.second;
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};