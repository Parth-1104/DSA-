class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        
        if(start<0 || start>=n || arr[start]<0)
        return false;
        if(arr[start]==0)
        return true;

       

        arr[start]*=-1;


        bool a =canReach(arr,start+arr[start]);
        bool b =canReach(arr,start-arr[start]);

        return a||b; 



    }
};