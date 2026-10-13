class Solution {
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {

        vector<int> result;

        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for (auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;

        for (int i = 0 ; i < n ; i ++)
        {
            if (indegree[i]==0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int elem = q.front();
            q.pop();
            result.push_back(elem);

            for (int nei : adj[elem])
            {
                indegree[nei]--;
                if (indegree[nei]==0)
                {
                    q.push(nei);
                }
            }
        }

        return (result.size() == n) ? result : vector<int>{};
    
    }
};
