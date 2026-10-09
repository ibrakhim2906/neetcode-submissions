class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for (int[] row : matrix) {
                if (binarySearch(row, target)!=-1) {
                    return true;
                }
            }
        
        return false;
    }

    public int binarySearch(int[] nums, int target) {
        int l=0;
        int r=nums.length-1;

        while (l<=r) {
            int m = (l+r)/2;

            if (target>nums[m]){
                l=m+1;
            } else if  (target<nums[m]){
                r=m-1;
            } else {
                return m;
            }
        }

        return -1;
    }
}

