class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    vector<int>arr;
     int m=0;
     for(int i=0;i<nums.size();i++)
     {
        mp[nums[i]]++;

        if(mp[nums[i]]>k)
        continue;

        else
        arr.push_back(nums[i]);

     }   

     return arr;
    }
};