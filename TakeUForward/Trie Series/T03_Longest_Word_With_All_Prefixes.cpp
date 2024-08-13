struct Node {
    Node *links[26];
    bool flag = false;

    bool contains(char c) {
        return links[c] != nullptr;
    }

    void insert(char c) {
        links[c] = new Node();
    }

    Node* get(char c) {
        return links[c];
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

    void insertWord(string word) {
        Node *node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->contains(word[i])) {
                node->insert(word[i]);
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool checkComplete(string word) {
        Node *node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->contains(word[i])) {
                return false;
            }
            else {
                node = node->get(word[i]);
                if(node->checkEnd() == false) {
                    return false;
                }
            }
        }
        return true;
    }

};

string longestCommonPrefix(vector<string> &arr, int n)
{   
    Trie *t = new Trie();
    // Write your code here
    for(int i=0; i<n; i++) {
        string word = arr[i];
        t->insertWord(word);
    }

    string longestStr = "";

    for (auto word : arr) {
        if (t->checkComplete(word)) {
            // Update if size is greater
            int wordSize = word.size();
            int longestStrSize = longestStr.size();
            if(wordSize > longestStrSize) {
                longestStr = word;
            }
            else if(wordSize == longestStrSize && word < longestStr) {
                longestStr = word;
            }
        }
    }

    return longestStr;
}


