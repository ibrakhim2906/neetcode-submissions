class Solution {
public:

    vector<vector<int>> memo;
    bool isInterleave(string s1, string s2, string s3) {

        memo.assign(s1.size()+1, vector<int>(s2.size()+1,-1));

        return dfs(0,0,0,s1,s2,s3);
        
    }

    bool dfs(int i, int j, int k, string& s1, string& s2, string& s3)
    {
        if (k == s3.size())
        {
            return (i==s1.size() && j == s2.size());
        }

        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        bool res = false;

        if (i < s1.size() && s1[i]==s3[k])
        {
            res =dfs(i+1,j,k+1,s1,s2,s3);
        }

        if (j < s2.size() && s2[j]==s3[k])
        {
            res = (dfs(i, j+1, k+1, s1,s2,s3));
        
        }

        memo[i][j] = res;

        return res;
    }
};
