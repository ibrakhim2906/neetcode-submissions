class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {

        backtrack(nums, {}, 0, nums.size());

        return res;

        
    }

    void backtrack(const vector<int>& nums, vector<int> cur, int i, int size)
    {
        if (i == size)

        {
            res.push_back({cur.begin(), cur.end()});
            return;
        }

        cur.push_back(nums[i]);

        backtrack(nums, cur, i+1, size);

        cur.pop_back();

        backtrack(nums, cur, i+1, size);
    }
};
