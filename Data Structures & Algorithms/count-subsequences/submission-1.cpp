class Solution {
public:

    vector<vector<int>> memo;
    int numDistinct(string s, string t) {

        memo.assign(s.size()+1, vector<int>(t.size()+1, -1));
        return dfs(0, 0, s, t);

        
        
    }

    int dfs(int i, int j, string& s, string& t)
    {

        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }
        if (j == t.size())
        {
            return 1;
        }

        if (i==s.size())
        {
            return 0;
        }

        int res = 0;

        if (s[i]==t[j])
        {
            res+=dfs(i+1, j+1, s, t);
        }

        res+=dfs(i+1, j, s, t);


        return memo[i][j] = res;


    }
};
