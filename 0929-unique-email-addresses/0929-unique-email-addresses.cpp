class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_set<string> uniqueEmails;

        for(string &email: emails){

            string cleanedLocal = "";
            string domain = "";
            bool foundAt = false;
            bool stopLocal = false;

            for(char c: email){

                if(c == '@'){
                    foundAt = true;
                    continue;
                }
                if(!foundAt){

                    if(c == '+'){
                        stopLocal = true;
                    }
                    if(!stopLocal && c!= '.'){
                        cleanedLocal = c;
                    }
                } else {
                    domain += c;
                }
            }
            string final = cleanedLocal + "@" + domain;
            uniqueEmails.insert(final);
        }
        return uniqueEmails.size();
    }
};