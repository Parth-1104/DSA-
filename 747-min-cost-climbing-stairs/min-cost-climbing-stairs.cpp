class Solution {
public:
   
    int t[1001];
    int help(vector<int>& cost,int i,int n)
    {
        if(i>=n)
        return 0;

        if(t[i]!=-1)
        return t[i];

        int ones=cost[i]+help(cost,i+1,n);
        int twos=cost[i]+help(cost,i+2,n);


        return t[i]= min(ones,twos);

    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        memset(t,-1,sizeof(t));
        int zeroIndex=help(cost,0,n);
        int oneIndex=help(cost,1,n);


        return min(zeroIndex,oneIndex);

    }
};