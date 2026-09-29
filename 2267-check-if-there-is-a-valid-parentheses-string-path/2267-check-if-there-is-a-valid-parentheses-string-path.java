class Solution {

    char[][] grid;
    int m, n;
    Boolean[][][] dp;

    boolean solve(int i, int j, int count) {

        if (i >= m || j >= n) {
            return false;
        }

        if (grid[i][j] == '(') {
            count++;
        } else {
            count--;
        }

        if (count < 0) {
            return false;
        }

        if (i == m - 1 && j == n - 1) {
            return count == 0;
        }

        if (dp[i][j][count] != null) {
            return dp[i][j][count];
        }

        boolean right = solve(i, j + 1, count);
        boolean down = solve(i + 1, j, count);

        return dp[i][j][count] = right || down;
    }

    public boolean hasValidPath(char[][] grid) {
        this.grid = grid;
        this.m = grid.length;
        this.n = grid[0].length;

        dp = new Boolean[m][n][m + n + 1];

        return solve(0, 0, 0);
    }
}