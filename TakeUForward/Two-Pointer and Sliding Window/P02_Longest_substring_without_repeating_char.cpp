class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int l = 0, r = 0, maxLength = 0;
        
        // {char, index}
        unordered_map<char, int> hash;

        while(r < size) {
            char c = s[r];

            // Have not seen this character
            if(hash.find(c) == hash.end()) {
                hash[c] = r;
            }
            else {
                // Find index of previous seen char
                int index = hash[c];
                // Update the hash to new index
                hash[c] = r;
                // Update left to index+1 if l < index+1
                l = max(l, index+1);
            }
            maxLength = max(maxLength, r - l + 1);
            r++;
        }
        return maxLength;
    }
};