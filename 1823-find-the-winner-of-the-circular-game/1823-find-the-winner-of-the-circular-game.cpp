class Solution {
public:
    
    int f(vector<int> &person,int k,int index)
    {
        if(person.size()==1) return person[0];
        else
        {
            int newIndex=(index+k-1)%person.size();
            person.erase(person.begin()+newIndex);
            return f(person,k,newIndex);
        }
    }
    
    int findTheWinner(int n, int k) 
    {
        vector<int> person;
        for(int i=1;i<=n;i++)
            person.push_back(i);
        int index=0;
        return f(person,k,index);
    }
};