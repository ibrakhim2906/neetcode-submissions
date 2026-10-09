class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {

        vector<int> comb;

        backtrack(1, n, k, comb);

        return res;
    }

    void backtrack(int begin, int end, int k, vector<int>& comb)
    {
        if (comb.size()==k)
        {
            res.push_back({comb.begin(), comb.end()});
        }

        for (int i = begin; i <= end; i++)
        {
            comb.push_back(i);
            backtrack(i+1, end, k, comb);
            comb.pop_back();
        }
    }
};