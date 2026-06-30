class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n = code.size();
        vector<int> res(n, 0);
        int sum = 0, elementOut, elementIn;

        if (k == 0) return res;
        else if(k>0)
        {
            for(int i = 1; i <= k; i++)
                sum += code[i % n];

            for(int i = 0; i < n; i++)
            {
                res[i] = sum;
                elementOut = (i + 1) % n;
                elementIn = (i + 1 + k) % n;

                sum = (sum - code[elementOut]) + code[elementIn];
            }
        }
        else
        {
            k = abs(k);
            for(int i = n - k; i < n; i++)
                sum += code[i];

            for(int i = 0; i < n; i++)
            {
                res[i] = sum;
                elementOut = (i + n - k)%n;
                elementIn = i;

                sum = (sum - code[elementOut]) + code[elementIn];
            }
        }
        return res;
    }
};