class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> nodeMap(n);
        vector<int> state(n, 0);

        for (auto& p : edges)
        {
            nodeMap[p[0]].push_back(p[1]);
            nodeMap[p[1]].push_back(p[0]);
        }

        if (!dfs(0, -1, nodeMap, state)) return false;

        for (int i = 0; i < n; i++)
        {
            if (state[i] != 2)
            {
                return false;
            }
        }

        return true;

    }

    bool dfs(int i, int parent, vector<vector<int>>& nodeMap, vector<int>& state)
    {
        if (state[i]==1) return false;
        if (state[i]==2) return true;

        state[i] = 1;
        for (int node : nodeMap[i])
        {

            if (node == parent)
            {
                continue;
            }
            if (!dfs(node, i, nodeMap, state)) return false;
        }

        state[i] = 2;
        return true;
    }
};
