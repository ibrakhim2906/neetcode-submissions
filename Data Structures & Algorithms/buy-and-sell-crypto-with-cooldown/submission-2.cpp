class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // can buy [i][1], can sell [i][0]
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));

        for (int i = prices.size()-1; i >= 0; i--)
        {
            for (int buying = 1; buying >= 0; buying --)
            {
            if (buying){

                int buy = dp[i+1][0]- prices[i];
                int cooldown = dp[i+1][1];
                
                dp[i][1] = max(buy, cooldown);

            } else {

                int sell = (i+2 < prices.size()) ? dp[i+2][1] + prices[i] : prices[i];

                int cooldown = dp[i+1][0];

                dp[i][0] = max(sell, cooldown);
            }
            }
        }

        return dp[0][1];


        
    }
};
