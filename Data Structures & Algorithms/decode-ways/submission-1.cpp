class Solution {
public:

    unordered_map<int, int> cache;
    int numDecodings(string s) {



        return dfs(0, s);

        
        
    }
    
    int dfs(int i, const string& s)
    {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        if (cache.contains(i)) return cache[i];
        cache[i] = dfs(i+1, s );
        if (i < s.size()-1){
        if (s[i] == '1' || (s[i]=='2' && s[i+1] < '7'))
        {

            cache[i]+=dfs(i+2, s);
            
        }
        }

        return cache[i];
    }
    
};
