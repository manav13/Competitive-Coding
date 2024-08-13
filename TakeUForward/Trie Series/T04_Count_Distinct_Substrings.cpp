struct Node {
    Node *links[26];

    bool contains(char c) {
        return links[c-'a'] != nullptr;
    }

    void put(char c) {
        links[c-'a'] = new Node();
    }

    Node* get(char c) {
        return links[c-'a'];
    }
};

class Trie {

private:
    Node *root;

public:

    Trie() {
        root = new Node();
    }

    int insert(string word, int startIndex) {
        Node *node = root;
        int count = 0;
        for(int i=startIndex; i<word.size(); i++) {
            if(!node->contains(word[i])) {
                count++;
                node->put(word[i]);
            }
            node = node->get(word[i]);
        }
        return count;
    }

};

int countDistinctSubstrings(string &s)
{
    Trie *t = new Trie();
    // Initialize 1 for empty substring
    int ans = 1;
    for(int i=0; i<s.size(); i++) {
        int count = t->insert(s, i);
        ans += count;
    }
    return ans;
}