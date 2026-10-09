class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxCount=0;
        int currCount=0;

        for (int i = 0; i<nums.length; i++) {
            if (nums[i]==1) {
                currCount++;
            }

            if (nums[i]==0 || i == nums.length-1) {
                maxCount = Math.max(currCount, maxCount);
                currCount = 0;
            }
        }

        return maxCount;
    }
}