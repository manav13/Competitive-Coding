class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size();
        int l=0, r=0, count = 0;
        vector<int> freq(26, 0);
        int maxFreq = 0;
        while(r < size) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            int maxReplacements = (r-l+1) - maxFreq;
            if(maxReplacements > k) {
                freq[s[l]-'A']--;
                l++;
            }
            count = max(count, r-l+1);
            r++;
        }
        return count;
    }
};