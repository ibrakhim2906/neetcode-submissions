class UnionFind
{

    public:
    unordered_map<int, int> rank;
    unordered_map<int, int> parent;

    int numComponents;

    UnionFind(int n)
    {

        numComponents = n;
        for (int i = 0 ; i < n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
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
        int x1 = find(x);
        int y1 = find(y);

        if (x1 == y1)
        {
            return false;
        }

        if (rank[x1]>rank[y1])
        {
            parent[y1] = x1;
        } else if (rank[y1]>rank[x1])
        {
            parent[x1] = y1;
        } else {
            parent[x1] = y1;
            rank[y1] += 1;
        }

        numComponents--;

        return true;
        
    }

};
class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        for (auto edge : edges)
        {
            int w = edge[2], n1 = edge[0], n2 = edge[1];
            minHeap.push({w, n1, n2});
        }

        int total =0;

        UnionFind uf(n);

        while (!minHeap.empty())
        {
            auto min = minHeap.top();
            minHeap.pop();
            if (uf._union(min[1], min[2]))
            {
                total+=min[0];
                
            }
        }
        
        return (uf.numComponents == 1) ? total : -1;

        




    
    }
};
