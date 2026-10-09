class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> subset;

        sort(nums.begin(), nums.end());

        backtrack(res, nums, subset, 0, nums.size());

        return res;
        
    }

    void backtrack(vector<vector<int>>& res, const vector<int>& nums, vector<int>& subset, int i, int size)
    {
        if (i == size)
        {

            res.push_back({subset.begin(), subset.end()});
            return;
        }

        subset.push_back(nums[i]);

        backtrack(res, nums, subset, i+1, size);

        subset.pop_back();

        int tmp = i;

        while (tmp+1 < nums.size() && nums[tmp] == nums[tmp+1])
        {
            tmp++;
        }

        backtrack(res, nums, subset, tmp+1, size);

    }
};
