/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    
    let myMap = new Map();
    let duplicate=[];
    nums.forEach((char)=>
    {
        if (myMap.has(char) == true) {
            duplicate.push(char);
        }
        
    else {
        myMap.set(char, 1);
    }   
    })
    
    return duplicate;
    
};