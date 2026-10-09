class TrieNode {
    public Map<Character, TrieNode> children;
    
    public boolean word;

    public TrieNode() {
        this.word = false;
        this.children = new HashMap<>();
    }
}

class WordDictionary {

    public TrieNode root;

    public WordDictionary() {
        root = new TrieNode();
    }

    public void addWord(String word) {
        TrieNode curr = root;

        for (char c : word.toCharArray()) {
            if (!curr.children.containsKey(c)) {
                curr.children.put(c, new TrieNode());
            }
            curr = curr.children.get(c);
        }
        curr.word = true;
    }

    public boolean search(String word) {
        return dfs(word, 0, root);
    }

    public boolean dfs(String word, int j, TrieNode root) {
        TrieNode curr = root;
        
        for (int i=j; i<word.length(); i++) {
            char c = word.charAt(i);
            if (c=='.') {
                for (TrieNode child : curr.children.values()) {
                    if (dfs(word, i+1, child)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (!curr.children.containsKey(c)) {
                    return false;
                }
                curr=curr.children.get(c);
            }
        }

        return curr.word;
    }
}
