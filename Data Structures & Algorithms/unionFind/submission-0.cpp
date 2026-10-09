class UnionFind {
public:

    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    int numComponents;
    UnionFind(int n) : numComponents{n} {

        for (int i = 1; i<=n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

    }

    int find(int x) {

        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];

    }

    bool isSameComponent(int x, int y) {

        int parent_x = find(x), parent_y = find(y);

        return parent_x == parent_y;

    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {

        int parent_x = find(x), parent_y = find(y);
        
        if (parent_x == parent_y)
        {
            return false;
        }

        if (rank[parent_x] > rank[parent_y])
        {
            parent[parent_y] = parent_x;
        } else if (rank[parent_y] > rank[parent_x])
        {
            parent[parent_x] = parent_y;
        } else {
            parent[parent_x] = parent_y;
            rank[parent_y] += 1;
        }

        numComponents--;

        return true;
        
    }

    int getNumComponents() {

        return numComponents;

    }
};
