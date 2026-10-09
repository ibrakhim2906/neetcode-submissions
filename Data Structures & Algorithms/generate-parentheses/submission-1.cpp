class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        string substring;

        backtrack(n, 0, 0, substring, res);
        
        return res;

        
    }

    void backtrack(int n, int open, int close, string& substring, vector<string>& res)
    {
        if (close == n)
        {
            res.push_back(substring);
            return;
        }

        if (open < n)
        {
            substring.push_back('(');
            backtrack(n, open + 1, close, substring, res);
            substring.pop_back();
        }

        if (close < open)
        {
            substring.push_back(')');
            backtrack(n, open, close + 1, substring, res);
            substring.pop_back();
        }
    }
};