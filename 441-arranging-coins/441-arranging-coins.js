/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function(n) 
{
    var count=0;
    var rows=1;
    while(n>0)
     {
         n=n-rows;
         if(n>=0) count=count+1;
         else break;
         rows=rows+1;
     }
    return count;
};