class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
        int res = 0;
        int start = 0;

        int i = 0;
        while (i < n) {
            int j = start;

            while (j <= i - k + 1) {
                if (dp[j][i]) {
                    res++;
                    start = i + 1;
                    break;
                }
                j++;
            }

            i++;
        }

        return res;
    }
};