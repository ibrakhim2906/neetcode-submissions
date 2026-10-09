class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int, int> count;
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        for (int num : nums)
        {
            count[num]++;
        }

        vector<int> perm;

        backtrack(nums, perm);

        return res;

        
        
    }

    void backtrack(vector<int>& nums, vector<int>& perm)
    {
        if (nums.size() == perm.size())
        {
            res.push_back({perm.begin(), perm.end()});
        }

        for (auto& [num,cnt] : count)
        {
            if (cnt>0)
            {
                perm.push_back(num);
                cnt--;
                backtrack(nums, perm);
                cnt++;
                perm.pop_back();
            }
        }
    }
};