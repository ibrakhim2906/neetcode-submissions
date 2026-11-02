class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n =  nums.size();
        
        vector<vector<int>> memo(n, vector<int>(n+1, -1));

        return dfs(nums, 0, -1, memo);
       
    }

    int dfs(vector<int>& nums, int i , int j, vector<vector<int>>& memo)
    {
        if (i == nums.size())
        {
            return 0;
        }

        if (memo[i][j+1]!=-1)
        {
            return memo[i][j+1];
        }

        int LIS = dfs(nums, i+1, j, memo);

        if (j == -1 || nums[j]<nums[i])
        {
            LIS = max(LIS, 1+dfs(nums, i+1, i, memo));
        }

        memo[i][j+1] = LIS;

        return LIS; 
    } 
};
