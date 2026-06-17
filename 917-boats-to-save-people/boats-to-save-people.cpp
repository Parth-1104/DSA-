class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());

        int i=0,j=people.size()-1;
        int totalBoats=0;
        while(i<=j)
        {
            int count=people[i]+people[j];

            if(count<=limit)
            {
                i++;
                j--;
                totalBoats++;
            }
            else{
                j--;
                totalBoats++;
            }
        }

        return totalBoats;
    }
};