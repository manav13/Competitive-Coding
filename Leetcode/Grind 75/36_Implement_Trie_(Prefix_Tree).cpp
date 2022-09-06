struct Node {
    private:
    
    Node *links[26];
    bool flag = false;
    
    public:
    
    bool containsChar(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    
    void put(char ch, Node *node) {
        links[ch-'a'] = node;
    }
    
    Node* get(char ch) {
        return links[ch-'a'];
    }
    
    void setEnd() {
        flag = true;
    }
    
    bool getEnd() {
        return flag;
    }
};

class Trie {
    private:
    
    Node *root;
    
    public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int size = word.size();
        Node *node = root;
        for(int i=0; i<size; i++) {
            if(!node->containsChar(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        int size = word.size();
        Node *node = root;
        for(int i=0; i<size; i++) {
            if(!node->containsChar(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        int size = prefix.size();
        Node *node = root;
        for(int i=0; i<size; i++) {
            if(!node->containsChar(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */