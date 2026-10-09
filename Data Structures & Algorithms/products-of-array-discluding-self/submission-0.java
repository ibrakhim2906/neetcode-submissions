class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] prodArr = new int[nums.length];

        for (int idx=0; idx<nums.length; idx++) {
            int product=1;
            for (int i=0; i<nums.length; i++) {
                if (idx==i) {
                    continue;
                }
                product*=nums[i];
            }

            prodArr[idx]=product;
        
        }

        return prodArr;
        
    }
}  
