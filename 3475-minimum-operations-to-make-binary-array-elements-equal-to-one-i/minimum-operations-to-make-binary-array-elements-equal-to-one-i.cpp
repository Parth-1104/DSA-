class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len=2;
        int right=0;
        int n=nums.size();
        int count=0;

        while(len<n)
        {
            if(nums[right]==0)
            {
                for(int i=right;i<=len;i++)
                {
                    nums[i]=1-nums[i];
                }
                count++;
            }
            right++;
            len++;
        }

        for(int i:nums)
        {
         if(i==0)
         return -1;
        }

        return count;
    }
};