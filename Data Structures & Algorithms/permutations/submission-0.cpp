class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> perm;
        vector<bool> on(nums.size(), false);

        backtrack(res, nums, perm, on);

        return res;
        
    }

    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int> perm,vector<bool> on)
    {

        if (perm.size() == nums.size())
        {
            res.push_back({perm.begin(), perm.end()});
        }

        for (int i = 0 ; i < nums.size(); i++)
        {
            if (!on[i])
            {
                on[i] = true;
                perm.push_back(nums[i]);

                backtrack(res, nums, perm, on);
                
                on[i] = false;
                perm.pop_back();
            }
        }
        
    }
};
