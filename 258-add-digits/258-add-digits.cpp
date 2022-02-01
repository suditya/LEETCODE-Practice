class Solution {
public:
    int addDigits(int num) 
    {
//         while(num >= 10)
//         {
//             int sum=0;
//             int x=num;
//             while(x > 0)
//             {
//                 sum=sum+x%10;
                
//             } 
//         }
        if(num < 10) return num;
        else
        {
            int sum=0;
            while(num > 0)
            {
                sum=sum+num%10;
                num=num/10;
            }
            return addDigits(sum);
        }
    }
};