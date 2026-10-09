class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for (int[] row : matrix) {
            for (int num: row) {
                if (num==target) {
                    return true;
                }
            }
        }
        return false;
    }
}
