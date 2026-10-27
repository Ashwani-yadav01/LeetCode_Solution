
class Solution {
    int[][] dir = {
        {-1, 0}, {1, 0}, {0, 1}, {0, -1}
    };

    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;

        int[][] res = new int[m][n];
        Queue<int[]> q = new LinkedList<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.offer(new int[]{i, j});
                } else {
                    res[i][j] = -1;
                }
            }
        }

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int i = curr[0];
            int j = curr[1];

            for (int[] d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (ni >= 0 && ni < m &&
                    nj >= 0 && nj < n &&
                    res[ni][nj] == -1) {

                    res[ni][nj] = res[i][j] + 1;
                    q.offer(new int[]{ni, nj});
                }
            }
        }

        return res;
    }
}
