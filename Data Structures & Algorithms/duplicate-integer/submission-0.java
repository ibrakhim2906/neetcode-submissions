class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashSet<Integer> found = new HashSet<>();
        for (int num : nums) {
            if (!found.add(num)) {
                return true;
            }
        }
        return false;
    }
}