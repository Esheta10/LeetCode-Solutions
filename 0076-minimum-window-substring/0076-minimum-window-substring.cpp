class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.length();

        map<char, int> mp;

        for(char &ch : t){
            mp[ch]++;
        }
        int i=0,j=0;
        int requiredCount = t.length();

        int minStart = 0, minWindow = INT_MAX;

        while(j<n){
            
            char ch_j = s[j];
           
           //Step-1: j se char liya, zarrorat thi toh count ghata
           if(mp[ch_j] > 0)
                requiredCount--;

            mp[ch_j]--; // map mein se bhi uss character ki frequency ghata do
            
            //Step2: sabhi characters mil gaye, window valid(requiredCount == 0) toh ab shrink karo
            while(requiredCount == 0){
                if(minWindow > j-i+1){
                    minWindow = j-i+1;
                    minStart = i;
                }

                char ch_i = s[i]; // char ko yaad karo
                mp[ch_i]++; // uske map ko update karo
                if(mp[ch_i] > 0)    
                    requiredCount++;    // matlab ye character t mein hai, aur hume aage chahaiye
                i++;
            }
            j++;
         }
         return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
    }
};