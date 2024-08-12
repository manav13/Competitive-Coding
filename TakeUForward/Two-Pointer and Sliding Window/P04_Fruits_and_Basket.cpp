class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int size = fruits.size();
        int l = 0, r = 0, maxFruits = 0;
        // {type, numOfFruits}
        unordered_map<int, int> hash;

        while(r < size) {
            hash[fruits[r]]++;

            if(hash.size() > 2) {
                hash[fruits[l]]--;
                if(hash[fruits[l]] == 0)
                    hash.erase(fruits[l]);
                l++;
            }

            maxFruits = max(maxFruits, r-l+1);
            r++;
        }
        return maxFruits;
    }
};