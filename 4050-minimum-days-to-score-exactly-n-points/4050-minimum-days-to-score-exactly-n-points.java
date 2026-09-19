class Solution {
    public int minDays(int n) {
        if(n == 0) return  0;

        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);

        for(int k = 1; ; k++) {
            int points = k * (k + 1) / 2;
            if(points > n) break;

            dp[points] = Math.min(dp[points], k);

            for(int sc = points + 1; sc <= n; sc++) {
                if(dp[sc - points] != Integer.MAX_VALUE) {
                    dp[sc] = Math.min(dp[sc], dp[sc - points] + k + 1);
                }
            }
        }

        return dp[n];
    }
}