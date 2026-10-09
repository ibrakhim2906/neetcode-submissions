class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;

        sort(candidates.begin(), candidates.end());

        backtrack(res, candidates, subset, 0, target, 0);

        return res;
    }

    void backtrack(vector<vector<int>>& res, const vector<int>& candidates, vector<int>& subset,
                   int cur, int target, int i) {

        if (cur == target)
        {
            res.push_back({subset.begin(), subset.end()});

            return;
        }
        if (i == candidates.size() || cur > target) {
            return;
        }

        subset.push_back(candidates[i]);
        backtrack(res, candidates, subset, cur + candidates[i], target, i + 1);
        subset.pop_back();

        while (i+1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        backtrack(res, candidates, subset, cur, target, i+1);
    }
};
