class Solution {
    public void sortColors(int[] nums) {
        int[] arr = {0, 0, 0};

        for (int num: nums) {
            arr[num]++;
        }

        int i=0;
        for (int n = 0; n<arr.length; n++) {
            for (int j = 0; j<arr[n]; j++) {
                nums[i]=n;
                i++;
            }
        }
    }
}