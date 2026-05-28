class Solution {
public:
    int findMin(vector<int>& nums) {
       int l=0;
       int n=nums.size();
       int r=n-1;
        int resultIdx=0;

        while(l<r && nums[l]==nums[l+1])l++;
        while(r>l &&nums[r]==nums[r-1])r--;

       while(l<=r)
       {
        
        

        int mid =l+(r-l)/2;

        if(nums[resultIdx]>nums[mid])
        resultIdx=mid;

        if(nums[r]<nums[mid])
        l=mid+1;
        else{
            r=mid-1;
        }

       }

       return nums[resultIdx]; 
    }
};