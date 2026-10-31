class Solution {
    int m, n;
    int[][] grid;
    int[][] dp;
    int mod = 1_000_000_007;

    int solve(int i, int j) {

        if (i >= m || j >= n) return 0;

        if (i == m - 1 && j == n - 1) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        long rightMove = 0;
        long downMove = 0;

        int ri = i;
        int rj = j + 1;
        boolean right = true;

        while (ri < m && rj < n && grid[ri][rj] == 1) {
            if (right) {
                ri++;
            } else {
                rj++;
            }
            right = !right;
        }

        if (ri < m && rj < n) {
            rightMove = solve(ri, rj);
        }

        int di = i + 1;
        int dj = j;
        boolean down = true;

        while (di < m && dj < n && grid[di][dj] == 1) {
            if (down) {
                dj++;
            } else {
                di++;
            }
            down = !down;
        }

        if (di < m && dj < n) {
            downMove = solve(di, dj);
        }

        return dp[i][j] = (int)((rightMove + downMove) % mod);
    }

    public int uniquePaths(int[][] grid) {
        this.grid = grid;
        m = grid.length;
        n = grid[0].length;

        dp = new int[m][n];

        for (int[] row : dp) {
            java.util.Arrays.fill(row, -1);
        }

        return solve(0, 0);
    }
}