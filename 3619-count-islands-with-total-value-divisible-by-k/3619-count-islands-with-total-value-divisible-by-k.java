class Solution {
    int m, n;
    int[][] grid;
    int k;
    int dfs(int i, int j) {
        if (i < 0 || j < 0 || i > m || j > n || grid[i][j] == 0) {
            return 0;
        }

        int val = grid[i][j];
        grid[i][j] = 0;

        val += dfs(i + 1, j);
        val += dfs(i - 1, j);
        val += dfs(i, j + 1);
        val += dfs(i, j - 1);

        return val%k;
    }

    public int countIslands(int[][] grid, int k) {
        this.m = grid.length - 1;
        this.n = grid[0].length - 1;
        this.grid = grid;
        int count = 0;
        this.k=k;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (grid[i][j] != 0) {
                    int sum = dfs(i, j);
                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}