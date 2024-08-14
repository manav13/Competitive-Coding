class Solution {
public:
    int numberOfSubstrings(string s) {
        int size = s.size();
        int r = 0, count = 0;
        // a, b, c for index 0, 1, 2  and all initiated with zero
        vector<int> hash(3, -1);
        while(r < size) {
            hash[s[r] - 'a'] = r;
            if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1) {
                count = count + (1 + min(hash[0], min(hash[1], hash[2])));
            }
            r++;
        }

        return count;
    }
};