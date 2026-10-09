class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int maxSum = nums[0], minSum = nums[0];
        int maxCur = 0, minCur = 0;
        int total=0;

        for (int num : nums) {

            total+= num;
            maxCur = Math.max(maxCur+num, num);
            minCur = Math.min(minCur+num, num);
            
            maxSum = Math.max(maxSum, maxCur);
            minSum = Math.min(minSum, minCur);

        }
        
        return maxSum>0 ? Math.max(total-minSum, maxSum) : maxSum;
    }
}