class Solution {
public:
    string minWindow(string s, string t) {
        int l=0, r=0, count = 0;
        int size = s.size();

        unordered_map<char, int> hash;
        for(auto c : t) {
            hash[c]++;
        }

        int minLen = 1e9, start = -1;
        while(r < size) {
            if(hash[s[r]] > 0) {
                count++;
            }

            hash[s[r]]--;

            while(count == t.size()) {
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    start = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0)
                    count--;
                l++;
            }
            r++;
        }
        if(start == -1)
            return "";
        return s.substr(start, minLen);
    }
};