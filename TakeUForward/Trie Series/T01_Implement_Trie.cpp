struct Node {
    Node *links[26];
    bool flag = false;

    bool contains(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch) {
        links[ch - 'a'] = new Node();
    }

    Node* get(char ch) {
        return links[ch-'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool checkEnd() {
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
        }

        // Set the flag at the end of word to true;
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;

        for(int i=0; i<word.size(); i++) {
            if(!node->contains(word[i]))
                return false;

            node = node->get(word[i]);
        }

        return node->checkEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;

        for(int i=0; i<prefix.size(); i++) {
            if(!node->contains(prefix[i]))
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