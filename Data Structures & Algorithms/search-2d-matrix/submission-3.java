class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int columns = matrix[0].length;
        
        int left = 0;
        int right = rows*columns-1;

        while (left<=right) {
            int mid = left+(right-left)/2;

            int r = mid/columns;
            int c = mid%columns;
            
            int val = matrix[r][c];

            if (target>val) {
                left=mid+1;
            } else if (target<val){
                right=mid-1;
            } else {
                return true;
            }
        }

        return false;
    }
}
