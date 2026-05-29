class Solution {
public: 
    int solve(int num)
    {
        int sum=0;

        while(num>0)
        {
            int digit=num%10;
            sum=sum+digit;
            num=num/10;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=solve(nums[i]);
        }

        int minVal=nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]<minVal)
            minVal=nums[i];
        }

        return minVal;
    }
};