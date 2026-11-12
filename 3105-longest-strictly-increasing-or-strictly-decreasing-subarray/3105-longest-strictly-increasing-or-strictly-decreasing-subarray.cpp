class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int prev = -1;
                int count = 0;
                for (int k = i; k <= j; k++) {
                    if (prev == -1 || nums[k] > prev) {
                        count++;
                    } else {
                        break;
                    }
                    prev=nums[k];
                }
                res = max(count, res);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int prev = -1;
                int count = 0;
                for (int k = i; k <= j; k++) {
                    if (prev == -1 || nums[k] < prev) {
                        count++;
                    } else {
                        break;
                    }
                    prev=nums[k];
                }
                res = max(count, res);
            }
        }
        return res;
    }
};