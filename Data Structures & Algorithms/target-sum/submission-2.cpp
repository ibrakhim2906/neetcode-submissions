class Solution {
public:

    unordered_map<string, int> memo;
    int findTargetSumWays(vector<int>& nums, int target) {


        return dfs(0, target, nums);

        
    }

    int dfs(int i, int target, vector<int>&nums)
    {
        if (target==0 && i == nums.size())
        {
            return 1;
        }

        string key = to_string(i)+"#"+to_string(target);

        if (memo.contains(key))
        {
            return memo[key];
        }
        if (i == nums.size())
        {
            return 0;
        }

        int res = 0;

        res+=dfs(i+1, target-nums[i], nums);
        res+=dfs(i+1, target+nums[i], nums);

        return memo[key] = res;
    }
};
