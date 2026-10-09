class Solution {
    public int removeDuplicates(int[] nums) {
        int current = nums[0];
        int indexToPlace=1;
        int k = 1;
        for (int i=1; i<nums.length; i++) {
            if (current!=nums[i]) {
                current=nums[i];
                nums[indexToPlace]=current;
                indexToPlace++;
                k++;
            }
        }
        return k;
}}
