class Solution {
public:
//     map<pair<int,int>,int> dp;
    
//     int f(int n ,int target,int maxDoubles)
//     {
//         if(n== target) return 0;
//         else if(dp.find({n,maxDoubles})!=dp.end()) 
//         {
//             // cout<<"hi"<<dp[{n,maxDoubles}]<<"\n";
//             return dp[{n,maxDoubles}];
//         }
//         else
//         {
//             cout<<"hi";
//             if(maxDoubles>0 and n*2<=target)
//             {
//                 return dp[{n,maxDoubles}]=min(f(n+1,target,maxDoubles),f(n*2,target,maxDoubles-1))+1;
//             }
//             else
//                 return target-n;
//         }
//     }
    
    int minMoves(int n, int maxDoubles) 
    {
        int count=0;
        while(maxDoubles > 0 and n>0)
        {
            ++count;
            if(n%2==0)
            {
                n=n/2;
                --maxDoubles;
            }
            else
                n=n-1;
            
            
        }
        cout<<count<<" "<<n;
        return count+n-1;
    }
};