class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        set<string> res;
        for (string word : words)
        {
            for (string word1 : words)
            {

                if (word == word1)
                {
                    continue;
                }
                if(word.find(word1)!=string::npos)
                {
                    res.insert(word1);
                }
            }
        }

        return {res.begin(), res.end()};
        
    }
};