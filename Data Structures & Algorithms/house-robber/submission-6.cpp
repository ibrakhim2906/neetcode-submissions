class Solution {
public:
    unordered_map<int, int> cache;
    int rob(vector<int>& nums) {

        return max(dfs(0, nums), dfs(1,nums));
        
    }

    int dfs(int i, vector<int>& nums)
    {
        if (i>=nums.size()) return 0;

        if (cache.contains(i)) return cache[i];

        cache[i] = max(nums[i]+dfs(i+2, nums), dfs(i+1, nums));

        return cache[i];
    }
};
