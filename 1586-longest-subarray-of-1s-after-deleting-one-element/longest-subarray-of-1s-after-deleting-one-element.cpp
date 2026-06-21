class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal=0;
        int lastZero=-1;

        int zeroCount=0;
        int left=0;
        for(int right=0;right<nums.size();right++)
        {


            if(nums[right]==0)
            {
                left=lastZero+1;
                lastZero=right;
                zeroCount--;

            }

            maxVal=max(maxVal,right-left);


        }
        return maxVal;
    }
};