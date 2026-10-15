class Solution {
public:

    unordered_map<int, vector<int>> cache;
    int rob(vector<int>& nums) {

        if (nums.size() == 1) return nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
        cache[i]=vector<int>(2, -1);
        }

        return max(dfs(0, true, nums), dfs(1, false, nums));

        
        
    }

    int dfs(int i,bool flag, vector<int>& nums)
    {
        if (i >= nums.size() || (flag && i == nums.size()-1))
        {
            return 0;
        }

        if (cache[i][flag] != -1) return cache[i][flag];

        cache[i][flag] = max(dfs(i+1, flag, nums), nums[i] + dfs(i+2, flag, nums));
        
        return cache[i][flag];
    }
};
