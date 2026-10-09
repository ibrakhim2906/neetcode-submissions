class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> edgeMap(n);
        vector<int> visited(n, 0);

        int res = 0;

        for (auto edge : edges)
        {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i ++ )
        {
            if (visited[i] == 1)
            {
                continue;
            }

            dfs(i, edgeMap, visited);
            res++;
        }

        return res;

    }

    void dfs(int i, vector<vector<int>>& edgeMap, vector<int>& visited)
    {
        if (visited[i]==1)
        {
            return;
        }

        visited[i] = 1;
        for (int edge : edgeMap[i])
        {
            dfs(edge, edgeMap, visited);
        }
    }
};
