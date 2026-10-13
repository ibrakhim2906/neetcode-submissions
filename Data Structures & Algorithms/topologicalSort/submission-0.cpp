class Solution {
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> result;
        unordered_set<int> visited;
        unordered_set<int> path;

        for (int i = 0 ; i < n ; i ++)
        {
            if (!dfs(i, adj, n, result, visited,path))
            {
                return {};
            }
        }

        reverse(result.begin(), result.end());

        return result;
    
    }

    bool dfs(int src, vector<vector<int>>& adj, int n, vector<int>& result, unordered_set<int>& visited, unordered_set<int>& path)
    {
        if (visited.contains(src))
        {
            return true;
        }

        if (path.contains(src))
        {
            return false;
        }

        path.insert(src);


        for (int i = 0; i < adj[src].size(); i++)
        {
            if (!dfs(adj[src][i], adj, n, result, visited,path)) return false;;
        }

        path.erase(src);
        visited.insert(src);

        result.push_back(src);
        return true;
    }
};
