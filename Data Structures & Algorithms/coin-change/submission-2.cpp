class Solution {
public:

    unordered_map<int,int> memo;
    int coinChange(vector<int>& coins, int amount) {

        if (amount == 0 ) return 0;

        int res =  dfs(coins, amount);

        return (res>=1e9) ? -1 : res;
        
    }

    int dfs(vector<int>& coins, int amount)
    {
        if (amount <= 0) return 0;
        if (memo.contains(amount)) return memo[amount];

        int res = 1e9;
        for (int coin : coins)
        {
            if (amount-coin >= 0)
            {

                res = min(res, 1+dfs(coins, amount-coin));
                
            }
        }

        memo[amount] = res;

        return res;
    }
};
