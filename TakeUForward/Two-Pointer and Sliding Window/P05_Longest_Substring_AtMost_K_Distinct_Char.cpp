class Solution {
public:
    int longestSubstring(string s, int k) {
        int size = s.size();
        int l = 0, r = 0, maxLength = 0;
        // {type, freq}
        unordered_map<char, int> hash;

        while(r < size) {
            hash[s[r]]++;

            if(hash.size() > k) {
                hash[s[l]]--;
                if(hash[s[l]] == 0)
                    hash.erase(s[l]);
                l++;
            }

            maxLength = max(maxLength, r-l+1);
            r++;
        }
        return maxLength;
    }
};