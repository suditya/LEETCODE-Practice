/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head=new ListNode;
        ListNode* realHead=head;
        int carry=0;
        // int carry=0;
        while(l1!=NULL and l2!=NULL)
        {
            int a=l1->val;
            int b=l2->val;
            int sum=a+b+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* temp= new ListNode(sum);
            head->next=temp;
            head=temp;
            l1=l1->next;
            l2=l2->next;
            
        }
        while(l1!=NULL)
        {
            int sum=l1->val + carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* temp=new ListNode(sum);
            head->next=temp;
            head=temp;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int sum=l2->val + carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* temp=new ListNode(sum);
            head->next=temp;
            head=temp;
            l2=l2->next;
        }
        if(carry > 0)
        {
            ListNode* temp=new ListNode(carry);
            head->next=temp;
        }
        return realHead->next;
    }
};