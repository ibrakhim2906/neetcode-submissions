class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> subset = new ArrayList<>();

        backtrack(nums, 0, nums.length-1,subset, res);

        return res;
    }

    public void backtrack(int[] nums, int curr, int len, List<Integer> subset, List<List<Integer>> res) {
        if (curr>len) {
            res.add(new ArrayList<>(subset));
            return;
        }

        subset.add(nums[curr]);

        curr++;

        backtrack(nums, curr, len, new ArrayList<>(subset), res);

        subset.remove(subset.size()-1);

        backtrack(nums, curr, len, new ArrayList<>(subset), res);
    }
}


