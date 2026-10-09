class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result{};

        for (string s : strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());

            result[temp].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& pair : result)
        {
            res.push_back(pair.second);
        }

        return res;
    }
};
