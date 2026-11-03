class Solution {
public:

    vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {

        sort(coins.begin(), coins.end());

        memo.assign(coins.size()+1, vector<int>(amount+1, -1));
        return dfs(coins, 0, amount);
        
    }

    int dfs(vector<int>& coins, int i, int target)
    {
        if (target == 0)
        {
            return 1;
        }
        if (i >= coins.size())
        {
            return 0;
        }

        if (memo[i][target]!=-1) return memo[i][target];

        int res = 0;

        if (target>=coins[i])
        {
            res = dfs(coins, i+1, target);
            res += dfs(coins, i, target - coins[i]);
        }

        return memo[i][target] = res;

    }
};
