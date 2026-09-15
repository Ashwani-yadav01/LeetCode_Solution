class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        
        long long fhs = 0;
        long long shs = 0;
        for (int i = 0; i < n / 2; i++) {
            fhs += nums[i];
        }
        for (int i = n / 2; i < n; i++) {
            shs += nums[i];
        }
        int res = 0;
        if (fhs > shs) {
            res++;
        }
        int pointer = n / 2;
        for (int i = 1; i < n; i++) {
            fhs = fhs - nums[i-1] + nums[pointer];
            shs = shs + nums[i-1] - nums[pointer];
            pointer++;
            pointer=pointer%n;
            if (fhs > shs) {
                res++;
            }
        }
        return res;
    }
};