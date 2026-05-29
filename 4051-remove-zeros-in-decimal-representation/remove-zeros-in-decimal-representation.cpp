class Solution {
public:
    long long removeZeros(long long n) {
        string num=to_string(n);
        vector<int>store;
        for(int i=0;i<num.size();i++)
        {
            if(num[i]!='0')
            store.push_back(num[i]-'0');
        }

        long long ans =0;
        long long pos =1;
        int s=store.size();
        for(int i=s-1;i>=0;i--)
        {
            ans+=pos*store[i];
            pos*=10;
        }

        return ans;

    }
};