class UnionFind {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int v, int u) {
        int p_v = find(v);
        int p_u = find(u);

        if (p_v == p_u) {
            return false;
        }

        if (rank[p_v] > rank[p_u]) {
            parent[p_u] = p_v;
        } else if (rank[p_u] > rank[p_v]) {
            parent[p_v] = p_u;
        } else {
            parent[p_v] = p_u;
            rank[p_u]++;
        }

        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts
    ) {
        int n = accounts.size();
        UnionFind uf(n);

        unordered_map<string, int> emailToAcc;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                const string& email = accounts[i][j];

                if (emailToAcc.count(email)) {
                    uf.unite(i, emailToAcc[email]);
                } else {
                    emailToAcc[email] = i;
                }
            }
        }

        unordered_map<int, vector<string>> emailGroup;

        for (const auto& [email, accId] : emailToAcc) {
            int leader = uf.find(accId);
            emailGroup[leader].push_back(email);
        }

        vector<vector<string>> res;

        for (auto& [accId, emails] : emailGroup) {
            sort(emails.begin(), emails.end());

            vector<string> merged;
            merged.push_back(accounts[accId][0]);
            merged.insert(merged.end(), emails.begin(), emails.end());

            res.push_back(merged);
        }

        return res;
    }
};