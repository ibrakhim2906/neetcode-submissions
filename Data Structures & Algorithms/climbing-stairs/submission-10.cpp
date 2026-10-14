class Solution {
public:
    unordered_map<int, int> cache;
    int climbStairs(int n) {


        return dfs(n);
        
        

        
        
    }

    int dfs(int n)
    {
        if (n<=2) return n;
        if (cache.contains(n)) return cache[n];

        cache[n] = dfs(n-1) + dfs(n-2);

        return cache[n];

        
    }
};
