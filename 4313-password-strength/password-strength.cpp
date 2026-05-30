class Solution {
public:
    int passwordStrength(string password) {
     unordered_set<char>s;
    int counter=0;
        for(int i=0;i<password.size();i++)
        {
            if(s.find(password[i])==s.end())
            {
                if(password[i]>='a'&&password[i]<='z')
                counter+=1;
                if(password[i]>='A'&&password[i]<='Z')
                counter+=2;
                if(password[i]>='0'&&password[i]<='9')
                counter+=3;
                if(password[i]=='@'||password[i]=='#'||password[i]=='$'||password[i]=='!')
                counter+=5;

            }
            
            s.insert(password[i]);
        } 

        return counter;  
    }
};