class Solution {
public:

    unordered_map<int, int> cache;

    int minCostClimbingStairs(vector<int>& cost) {

        
        return min(dfs(0, cost), dfs(1, cost));
        
        
    }

    int dfs(int i, vector<int>& cost)
    {

        if (i>=cost.size()) return 0;

        if (cache.contains(i)) return cache[i];

        cache[i] = cost[i] + min(dfs(i+1, cost), dfs(i+2, cost));

        return cache[i];

    }
};
