class Solution {
public:
    bool judgeCircle(string moves) 
    {
        int x=0;
        int y=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='U')
            {
                x=x-1;
            }
            if(moves[i]=='D')
            {
                x=x+1;
            }
            if(moves[i]=='L')
            {
                y=y-1;
            }
            if(moves[i]=='R')
            {
                y=y+1;
            }
        }   
        return (x==0 and y==0);
        
    }
};