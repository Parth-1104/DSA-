class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0,right=0,product=1,result=0;

        for(int right=0;right<nums.size();right++)
        {
            product*=nums[right];
            while(product>=k && left<=right)
            {
                product/=nums[left];
                left++;
            }

            result+=right-left+1;
        }

        return result;
    }
};