class Solution {
public:

    unordered_map<string, int> dp;
    int maxProfit(vector<int>& prices) {

        return dfs(0, true, prices);
        
    }

    int dfs(int i , bool allowedBuy, vector<int>& prices) 
    {

        if (i >= prices.size())
        {
            return 0;
        }

        string key = to_string(i)+"-"+to_string(allowedBuy);

        if (dp.contains(key))
        {
            return dp[key];
        }

        int cooldown = dfs(i+1, allowedBuy, prices);

        if (allowedBuy) {
            int buy = dfs(i+1, false, prices) - prices[i];
            dp[key] = max(buy, cooldown);
        } else {
            int sell = dfs(i+2, true, prices) + prices[i];
            dp[key] = max(cooldown, sell);
        }

        return dp[key];

    }
};
