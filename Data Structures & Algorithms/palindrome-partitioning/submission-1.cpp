class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> res;

        vector<string> substr;

        backtrack(res, s, substr, 0);
        return res;
    }

    void backtrack(vector<vector<string>>& res, const string& s, vector<string>& substr, int i)
    {

        if (i >= s.length())
        {
            res.push_back(substr);
            return;
        }

        for (int j = i; j<s.length(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                substr.push_back(s.substr(i, j-i+1));

                backtrack(res, s, substr, j+1);

                substr.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int start, int i)
    {
        bool valid = true;
        int l = start, r = i;

        while (l<r)
        {
            if (s[l] != s[r])
            {
                valid = false;
            }

            l++;
            r--;
        }

        return valid;
    }
};