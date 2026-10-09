class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> res;
        vector<vector<int>> preMap(numCourses);
        vector<int> state(numCourses, 0);

        for (auto& p : prerequisites)
        {
            preMap[p[0]].push_back(p[1]);
        }

        for (int c = 0 ; c < numCourses; c++)
        {
            if (!dfs(c, preMap, state, res))
            {
                return {};
            }
        }

        return res;
        
        
    }

    bool dfs(int c, vector<vector<int>>& preMap,vector<int>& state, vector<int>& res)
    {

        if (state[c]==1) return false;
        if (state[c]==2) return true;

        state[c]=1;

        for (int pre : preMap[c])
        {
            if (!dfs(pre, preMap, state, res)) return false;
        }

        state[c] = 2;
        res.push_back(c);

        return true;

    }
};
