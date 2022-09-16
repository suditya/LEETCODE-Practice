/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    
    const map = new Map();
    // nums.forEach((num, index)=>
    // {
    //     map.set(num, index);
    //     // console.log(map.get(num))
    // });
    
    let pairs=[];
    
    nums.forEach((num, index)=>
    {
        if(map.get(target-num)!=undefined)
            {
                pairs.push(map.get(target-num));
                pairs.push(index);
                return pairs;
            }
        // if(pairs.length > 1 )return pairs;
         map.set(num, index);
    });
    
    return pairs;
    
};