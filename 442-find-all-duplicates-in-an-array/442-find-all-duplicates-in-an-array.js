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
        // let prevCount = myMap.get(char);
        // myMap.set(char, prevCount + 1);
        // if (prevCount + 1 > ans) {
        //     ans = prevCount + 1;
        //     ansChar = char;
            
            duplicate.push(char);
        }
        
    else {
        myMap.set(char, 1);
    }   
    })
    
    return duplicate;
    
};