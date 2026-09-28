class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {

        int m = matrix.length;
        int n = matrix[0].length;

        int i = 0;
        int j = m - 1;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (matrix[mid][n - 1] == target) {
                return true;
            }

            if (matrix[mid][n - 1] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        int row = i;

        if (i == m || i < 0) {
            return false;
        }

        int low = 0;
        int high = matrix[row].length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[row][mid] == target) {
                return true;
            }

            if (matrix[row][mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
}