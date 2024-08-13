struct Node {
    Node *links[2];

    void put(int i) {
        links[i] = new Node();
    }

    Node* get(int i) {
        return links[i];
    }

    bool contains(int i) {
        return links[i] != nullptr;
    }
};

class Trie {

private:

    Node *root;

public:

    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node *node = root;
        for(int i=31; i>=0; i--) {
            // check if the bit is set or not
            int bit = (num >> i) & 1;
            if(!node->contains(bit)) {
                node->put(bit);
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node *node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--) {
            // check if the bit is set or not
            int bit = (num >> i) & 1;

            // in order to maximize, we need the reverse of the bit which is equal to (1-bit)
            if(node->contains(1-bit)) {
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *t = new Trie();

        for(auto num : nums) {
            t->insert(num);
        }
        int ans = INT_MIN;
        for(auto num : nums) {
            int temp = t->getMax(num);
            ans = max(ans, temp);
        }

        return ans;
    }
};