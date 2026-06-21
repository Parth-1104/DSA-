class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.empty()|| t.empty()|| s.size()<t.size())
        return "";

        int left=0,right=0;
        int minLen=INT_MAX;
        int startIndex=-1; 
        int count=t.size();   
        unordered_map<char,int>mp;

        for(int i=0;i<t.size();i++)
        {
            char charAt=t[i];
            mp[charAt]++;

        }

        while(right<s.size())
        {   
            char atRight=s[right];
            if(mp.find(atRight)!=mp.end())
            {
                if(mp[atRight]>0)
                count--;

                mp[atRight]--;
            }
            right++;

            while(count==0)
            {
                if(right-left<minLen)
                {
                    startIndex=left;
                    minLen=right-left;
                }
                char atLeft=s[left];
                if(mp.find(s[left])!=mp.end())
                {
                    mp[s[left]]++;

                    if(mp[s[left]]>0)
                    {
                        count++;
                    }
                }

                left++;
                
            }
           
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};