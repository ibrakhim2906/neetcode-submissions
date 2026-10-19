class Solution {
public:

    unordered_map<int, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {

        return dfs(s, wordDict, 0);

        
        
    }

    bool dfs(string& s, vector<string>& wordDict, int i)
    {
        if (memo.count(i))
        {
            return memo[i];
        }

        if (i == s.size())
        {
            return true;
        }

        for (const string& word : wordDict)
        {
            if (i+word.length()<=s.size() &&
                s.substr(i, word.size())==word)
                {
                    if (dfs(s, wordDict, i+word.size()))
                    {
                        memo[i]=true;
                        return true;
                    }
                }
        }

        memo[i] = false;

        return false;
    }
};
