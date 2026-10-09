class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if (endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        {
            return 0;
        }

        unordered_map<string, vector<string>> nei;
        wordList.push_back(beginWord);

        for (string& word : wordList)
        {
            for (int j = 0; j < word.size(); j++)
            {
                string pattern = word.substr(0, j) + "*" + word.substr(j+1);
                nei[pattern].push_back(word);
            }
        }

        unordered_set<string> visit{beginWord};
        deque<string> q;
        q.push_back(beginWord);
        int res = 1;

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                string word = q.front();
                q.pop_front();
                if (word == endWord)
                {
                    return res;
                }

                for (int i = 0 ; i < word.size(); i++)
                {
                    string pattern = word.substr(0, i) + "*" + word.substr(i+1);
                    
                    for (string& nWord : nei[pattern])
                    {
                        if (!visit.contains(nWord))
                        {
                            visit.insert(nWord);
                            q.push_back(nWord);
                        }
                    }
                }
            }
            res++;
        }

        return 0;
        
    }

};
