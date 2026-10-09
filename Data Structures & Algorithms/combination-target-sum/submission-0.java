class Solution {
    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> out = new ArrayList<>();
        List<Integer> sub = new ArrayList<>();
        dfs(nums, 0, 0,sub, out, target);
        return out;
    }

    public void dfs(int[] nums, int i,int curSum,List<Integer> sub, List<List<Integer>> out, int target) {
        if (curSum==target) {
            out.add(new ArrayList<>(sub));
            return;
        }
        if (i>=nums.length || curSum>target) {
            return;
        }

        sub.add(nums[i]);
        dfs(nums, i, curSum+nums[i], sub, out, target);
        sub.remove(sub.size() - 1);
        dfs(nums, i+1, curSum, sub, out, target);
    }
}
