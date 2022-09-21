/**
 * @param {number} n
 * @return {number}
 */


var makePrimes=function(n)
{
    var isPrime=[];
    for(let i=0;i<n;i++) isPrime.push(true);
    
    isPrime[0]=false;
    isPrime[1]=false;
    isPrime[2]=true;
    
    for(let i=2;i*i<n;i++)
    {
        if(isPrime[i]===true)
        {
            for(let j=i*i;j<n;j=j+i)
            {
                isPrime[j]=false;
            }
        }
    }
     
    return isPrime
    
}

var countPrimes = function(n) {
    if(n<=2) return 0;
    // if(n==2) return 1;
    if(n==3) return 1;
    let isPrime=makePrimes(n);
    let count=0;
    isPrime.forEach((prime,index)=>
    {
        // console.log(index, " ",prime);
        if(prime===true) ++count;  
    })
    
    return count;
};