class Solution {
public:

int findRight(vector<int>& nums, int target,int n)
    {
        int i=0;int j=n-1;
        int rightIndex=-1;

        while(i<=j)
        {
            int mid=i+(j-i)/2;

            if(nums[mid]==target)
            {
                rightIndex=mid;
                i=mid+1;
            }else if(nums[mid]>target)
            {
                j=mid-1;
            }else{
                i=mid+1;
            }
        }

        return rightIndex;
    }

    int findLeft(vector<int>& nums, int target,int n)
    {
        int i=0;int j=n-1;
        int leftIndex=-1;

        while(i<=j)
        {
            int mid=i+(j-i)/2;

            if(nums[mid]==target)
            {
                leftIndex=mid;
                j=mid-1;
            }else if(nums[mid]>target)
            {
                j=mid-1;
            }else{
                i=mid+1;
            }
        }

        return leftIndex;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int i=findLeft(nums,target,n);
        int j=findRight(nums,target,n);

        return {i,j};

    }
};