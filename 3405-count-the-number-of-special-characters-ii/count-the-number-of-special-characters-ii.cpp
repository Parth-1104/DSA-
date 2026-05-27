class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int>lower(26,-1);
        vector<int>upper(26,-1);

        int count=0;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];

            if(ch>='a' && ch<='z')
            lower[ch-'a']=i;

            if(ch>='A' && ch<='Z')
            if (upper[ch - 'A'] == -1) {
                    upper[ch - 'A'] = i;
                }
        }

        for(int i=0;i<26;i++)
        {
            if (lower[i] != -1 && upper[i] != -1) {
                if (lower[i] < upper[i]) {
                    count++;
                }
            }
        }

        return count;

    }
};