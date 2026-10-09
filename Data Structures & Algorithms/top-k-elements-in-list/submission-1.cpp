class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for (int n : nums)
        {
            count[n]+=1;
        }

        vector<vector<int>> freq(nums.size()+1);

        for (const auto& pair : count)
        {
            freq[pair.second].push_back(pair.first);
        }

        vector<int> res;

        for (int i = freq.size()-1; i>=0; i--)
        {
            for (int n : freq[i])
            {
                res.push_back(n);

                if (res.size()==k)
                {
                    return res;
                }
            }
        }

        return {};
        
    }
};
