class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        int rowMap[128] = {0}; // precomputed row-mapping for ASCII characters

        for(char ch: "qwertyuiopQWERTYUIOP")
            rowMap[ch] = 1;

        for(char ch: "asdfghjklASDFGHJKL")
            rowMap[ch] = 2;

        for(char ch: "zxcvbnmZXCVBNM")
            rowMap[ch] = 3;

        vector<string> result;
        for(const string &str : words){

            if(str.empty())
                continue;

            int targetRow = rowMap[str[0]];
            bool isValid = true;

            for(int i=1; i<str.size(); i++){

                if(rowMap[str[i]] != targetRow){
                    isValid = false;
                    break;
                }
            }
            if(isValid)
                result.push_back(str);
        }
        return result;
    }
};