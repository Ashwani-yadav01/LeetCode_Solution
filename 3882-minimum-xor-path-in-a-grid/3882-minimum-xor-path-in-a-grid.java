
import java.util.*;

class Solution {
    public int minCost(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        HashSet<Integer>[][] dp = new HashSet[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = new HashSet<>();
            }
        }

        dp[0][0].add(grid[0][0]);

        int[] dx = {0, 1};
        int[] dy = {1, 0};

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                for (int d : dp[x][y]) {
                    for (int k = 0; k < 2; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < n && ny < m) {
                            dp[nx][ny].add(d ^ grid[nx][ny]);
                        }
                    }
                }
            }
        }

        return Collections.min(dp[n - 1][m - 1]);
    }
}
