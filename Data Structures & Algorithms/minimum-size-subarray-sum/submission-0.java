class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int length=210391930;
        int L=0;
        int total=0;
        
        for (int R=0; R<nums.length; R++) {
            total+=nums[R];
            while (total>=target) {
                length = Math.min(length, R-L+1);
                total-=nums[L];
                L++;
            }
        }

        if (length==210391930) {
            return 0;
        }

        return length;
    }
}