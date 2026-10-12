class UnionFind {
    public:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;

        int numComponents;

        UnionFind(int n)
        {
            for (int i = 0 ; i < n ; i ++)
            {
                parent[i] = i;
                rank[i] = 0;
            }
            
            numComponents = n;
        }

        int find(int x)
        {
            if (x != parent[x])
            {
                parent[x] = find(parent[x]);
            }

            return parent[x];
        }

        bool _union(int x, int y)
        {
            int p_x = find(x);
            int p_y = find(y);

            if (p_x == p_y)
            {
                return false;
            }

            if (rank[p_x]>rank[p_y])
            {
                parent[p_y] = p_x;
            } else if (rank[p_y]>rank[p_x])
            {
                parent[p_x] = p_y;
            } else {
                parent[p_y] = p_x;
                rank[p_x] += 1;
            }

            numComponents--;

            return true;
        }
};
class Solution {
public:


    int kruskal(vector<vector<int>>& lst, int n, int force = -1, int skip = -1)
    {
        UnionFind uf(n);

        int total = 0;

        if (force!=-1)
        {
            for (auto& e : lst)
            {
                if (e[3] == force)
                {
                    uf._union(e[0],e[1]);
                    total += e[2];
                    break;
                }
            }
        }

        for (auto& e : lst)
        {

            if (e[3] == skip)
            {
                continue;
            }

            if (uf._union(e[0], e[1])) total += e[2];
            
            
        }

        return uf.numComponents == 1 ? total : INT_MAX;
    }

    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(2);
        vector<vector<int>> lst;

        for (int i = 0 ; i < edges.size() ; i++ )
        {
            lst.push_back({edges[i][0], edges[i][1], edges[i][2], i});
        }

        sort(lst.begin(), lst.end(), [](auto& a, auto& b){return a[2] < b[2];});

        int best = kruskal(lst, n);

        for (auto& e : lst)
        {
            if (kruskal(lst, n, -1, e[3]) > best) 
            {
                result[0].push_back(e[3]);
            }
            else if (kruskal(lst, n, e[3]) == best)
            {
                result[1].push_back(e[3]);

            }
        }


        return result;
    }
};