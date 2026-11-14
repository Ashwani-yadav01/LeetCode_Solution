class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + l - 1; j < n && j < i + r; j++) {
                int a = 0;
                for (int k = i; k <= j; k++) {
                    a += nums[k];
                }
                if (a > 0) {
                    res = min(res, a);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};