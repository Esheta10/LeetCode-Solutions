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
//Approach-1 : Reverse the linked list
    ListNode* reverseLL(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;
        while(curr!=NULL)
        {
           nextNode = curr->next; // Store the next node
           curr->next = prev;// Reverse the pointer
           prev = curr;// Move prev forward
           curr = nextNode;// Move curr forward
        }   
        return prev; // New head of the reversed list
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        int sum=0,carry=0;
        ListNode* ans = new  ListNode();
        while(l1!=NULL || l2!=NULL)
        {
            if(l1)
            {
                sum += l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum += l2->val;
                l2=l2->next;
            }
            ans->val = sum%10;
            carry = sum/10;
            ListNode * newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }
        return carry==0 ? ans->next : ans;
    }
};