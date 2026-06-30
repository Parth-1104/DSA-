class Solution {
public:

    void swap(string &s,int start , int end )
    {
        
    }
    string reversePrefix(string s, int k) {
        int start=0;
        int end =k-1;
        
        while(start<=end)
        {
            char temp= s[start];
            s[start]=s[end];
            s[end]=temp;

            start++;
            end--;
        }

        return s;
    }
};