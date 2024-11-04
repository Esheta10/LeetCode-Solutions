class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i=0;
        int index=0;

        while(i<n)
        {
            char curr_char=chars[i];
            int count=0;

            //find the number of duplicates
            while(i<n and chars[i]==curr_char)
            {
                count++;
                i++;
            }
            //now do the assign work
            chars[index]=curr_char;
            index++;

            //add the count
            if(count>1)
            {
                string count_str = to_string(count);
                for(char &ch : count_str)
                {
                    chars[index]=ch;
                    index++;
                }
            }
        }
        return index;
    }
};