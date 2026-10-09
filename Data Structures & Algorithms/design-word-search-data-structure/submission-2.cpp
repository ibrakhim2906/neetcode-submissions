class TrieNode
{
    public:
    TrieNode* childrens[26];
    bool endOfWord;

    TrieNode()
    {
        for ( int i = 0; i < 26; i++) {

            childrens[i] = nullptr;
        }

        endOfWord = false;
    }
};


class WordDictionary {

    TrieNode* root;
public:
    WordDictionary() {

        root = new TrieNode();
        
    }
    
    void addWord(string word) {

        TrieNode* cur = root;

        for (char c : word)
        {
            int i = c - 'a';
            if (cur->childrens[i]==nullptr)
            {
                cur->childrens[i] = new TrieNode();
            }

            cur = cur -> childrens[i];
        }

        cur->endOfWord = true;
        
    }
    
    bool search(string word) {

        return searchInTrie(root, word, 0);


        
        
    }

private:

    bool searchInTrie(TrieNode* root, string word, int j)
    {
        TrieNode*  cur = root;

        for (int i = j; i<word.size(); i++)
        {
            char c = word[i];

            if (c == '.')
            {
                for (TrieNode* child : cur->childrens)
                {
                    if (child != nullptr && searchInTrie(child, word, i+1))
                    {
                        return true;
                    }

                }

                return false;
            } else {
                if (cur->childrens[c-'a'] == nullptr)
                {
                    return false;
                }

                cur = cur->childrens[c-'a'];
            }
        }

        return cur->endOfWord;
    }
};
