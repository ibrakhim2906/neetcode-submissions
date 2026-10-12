class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        sort(tickets.rbegin(), tickets.rend());

        int n = tickets.size();

        unordered_map<string, vector<string>> adj;

        for (int i = 0; i < n ; i++)
        {
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }

        vector<string> result;
        dfs("JFK", adj, result);
        reverse(result.begin(), result.end());


        return result;

    }

    void dfs(const string& src, unordered_map<string, vector<string>>& adj, vector<string>& result)
    {

        while (!adj[src].empty())
        {
            string dst =  adj[src].back();
            adj[src].pop_back();
            dfs(dst, adj, result);
        }

        result.push_back(src);

    }
};
