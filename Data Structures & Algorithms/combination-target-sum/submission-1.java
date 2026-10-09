class Solution {
    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();

        List<Integer> subset = new ArrayList<>();

        backtrack(nums, 0, nums.length-1, subset, target, res);

        return res;

    }

    public void backtrack(int[] nums, int curr, int len, List<Integer> subset, int target, List<List<Integer>> res){
        int currSum = 0;
        for (int num : subset) {
            currSum+=num;
        }

        if (currSum == target) {
            res.add(new ArrayList<>(subset));
            return;
        }

        if (curr>len || currSum>target) {
            return;
        }

        subset.add(nums[curr]);

        backtrack(nums, curr, len, new ArrayList<>(subset), target, res);

        curr++;

        subset.remove(subset.size()-1);

        backtrack(nums, curr, len, new ArrayList<>(subset), target, res);
 
    } 
}
