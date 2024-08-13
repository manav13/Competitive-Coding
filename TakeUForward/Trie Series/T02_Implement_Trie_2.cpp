struct Node {
    Node *links[26];
    int cntEndWiths = 0;
    int cntStartsWith = 0;

    bool contains(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch) {
        links[ch - 'a'] = new Node();
    }

    Node* get(char ch) {
        return links[ch-'a'];
    }

    void increaseEnd() {
        cntEndWiths++;
    }

    void increasePrefix() {
        cntStartsWith++;
    }

    int getEndCount() {
        return cntEndWiths;
    }

    int getStartsWithCount() {
        return cntStartsWith;
    }
    
    void decreaseStartWithCount() {
        cntStartsWith--;
    }

    void removeEndWith() {
        cntEndWiths--;
    }
};

class Trie {

private:

    Node *root;

public:
    Trie() {
        root = new Node();
    }
    
    // TC = O(len(word))
    void insert(string word) {
        Node *node = root;

        for(int i=0; i<word.size(); i++) {
            // Check if node contains the character
            if(!node->contains(word[i])) {
                node->put(word[i]);
            }

            // Traverse to next node;
            node = node->get(word[i]);
            node->increasePrefix();
        }

        // Set the flag at the end of word to true;
        node->increaseEnd();
    }
    
    int countWordsEqualTo(string word) {
        Node *node = root;

        for(int i=0; i<word.size(); i++) {
            if(!node->contains(word[i]))
                return 0;

            node = node->get(word[i]);
        }

        return node->getEndCount();
    }
    
    int countWordsStartingWith(string prefix) {
        Node *node = root;

        for(int i=0; i<prefix.size(); i++) {
            if(!node->contains(prefix[i]))
                return 0;

            node = node->get(prefix[i]);
        }

        return node->getStartsWithCount();
    }

    void erase(string word) {
        Node *node = root;

        for(int i=0; i<word.size(); i++) {
            node = node->get(word[i]);
            node->decreaseStartWithCount();
        }
        node->removeEndWith();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */