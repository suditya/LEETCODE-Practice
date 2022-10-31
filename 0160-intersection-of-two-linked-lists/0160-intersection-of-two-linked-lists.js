/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    let map = new Map();
    // let ans= null;
    // map.set(headA,1);
    // map.set(headB,1);
    while(headA !== null)
    {
        map.set(headA, 1);
        headA=headA.next;
    }
    
    while(headB !== null)
    {
        // map.set(headB.next, 1);
        if(map.has(headB)===true) return headB;
        headB=headB.next;
    }
    
    
    return null;
    
};