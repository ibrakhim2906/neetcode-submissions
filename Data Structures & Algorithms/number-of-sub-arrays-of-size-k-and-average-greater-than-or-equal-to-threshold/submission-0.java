class Solution {
    public int numOfSubarrays(int[] nums, int k, int threshold) {
        int count = 0;
        int L=0;
        int targetSum = k*threshold;

        int curSum=0;

        for (int R=0; R<nums.length; R++) {
            curSum=curSum+nums[R];

            if (R-L+1>k) {
                curSum=curSum-nums[L];
                L++;
            }

            if (R-L+1==k && curSum>=targetSum) {
                count++;
            }
        }

        return count;
    }
}