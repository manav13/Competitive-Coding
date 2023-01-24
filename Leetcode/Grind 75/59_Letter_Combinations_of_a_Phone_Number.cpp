class Solution {
public:
    
    unordered_map<char, string> getLetter() {
        unordered_map<char, string> hash;
        hash['1'] = "";
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";
        
        return hash;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        
        unordered_map<char, string> hash = getLetter();
        vector<string> midResult = letterCombinations(digits.substr(1));
        vector<string> finalResult;
        for(auto c : hash[digits[0]]) {
            if(midResult.size() == 0) {
                string str = "";
                str += c;
                finalResult.push_back(str);
            }
            else {
                for(auto str : midResult) {
                    str = c + str;
                    finalResult.push_back(str);
                }
            }
        }
        return finalResult;
    }
};