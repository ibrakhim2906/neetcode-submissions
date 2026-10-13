class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for (auto preq : prerequisites)
        {
            adj[preq[0]].push_back(preq[1]);
            indegree[preq[1]]++;
            
        }

        queue<int> q;

        for (int i = 0 ; i < numCourses; i++)
        {
            if (indegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<unordered_set<int>> isPrereq(numCourses);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (int nei : adj[front])
            {

                isPrereq[nei].insert(front);
                isPrereq[nei].insert(isPrereq[front].begin(), isPrereq[front].end());
                indegree[nei]--;

                if (indegree[nei] == 0) q.push(nei);

            }
        }

        vector<bool> res;

        for (auto& query : queries)
        {
            res.push_back(isPrereq[query[1]].contains(query[0]));
        }

        return res;


        
    }
};