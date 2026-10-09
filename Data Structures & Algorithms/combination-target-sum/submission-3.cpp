class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res{};
        vector<int> subset{};
        backtrack(nums, 0, subset, 0, target, res);

        return res;
        
    }

    void backtrack(const vector<int>& nums, int i, vector<int>& subset, int curSum, int target, vector<vector<int>>& res)
    {
        if (curSum == target)
        {
            res.push_back(subset);
            return;
        }
        if (i == nums.size() || curSum > target)
        {

            return;
        }

        subset.push_back(nums[i]);
        curSum += nums[i];
        backtrack(nums, i, subset, curSum, target, res);

        subset.pop_back();
        curSum -= nums[i];
        backtrack(nums, i+1, subset, curSum, target, res);
    }
};
