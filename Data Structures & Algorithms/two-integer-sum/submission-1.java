class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i<nums.length; i++) {
            map.put(nums[i], i);
        }

        for (int i = 0; i<nums.length; i++) {
            int remainder = target-nums[i];
            if (map.containsKey(remainder)) {
                if (map.get(remainder)!=i) {
                    return new int[]{i, map.get(remainder)};
                }
            }
        }
        return new int[2];
    }
}
