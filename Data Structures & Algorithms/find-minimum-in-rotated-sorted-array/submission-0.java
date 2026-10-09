class Solution {
    public int findMin(int[] nums) {
        int minIndex=0;
        int minValue=2147483647;

        for (int i = 0; i<nums.length; i++) {
            if (nums[i]<minValue) {
                minValue=nums[i];
                minIndex=i;
            }
        }

        return minValue;

        // int len = nums.length;

        // for (int i = 0; i<nums.length; i++) {
        //     int temp = nums[i];
        //     nums[i]=nums[(len+minIndex)%len];
        //     nums[(len+minIndex)%len]=temp;
        // }
    }
}
