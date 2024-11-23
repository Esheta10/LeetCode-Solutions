/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head)
    {
        int length = 0;
        while(head)
        {
            length++;
            head=head->next;
        }
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;

        int lenA = getLength(headA);
        int lenB = getLength(headB);

        while(lenA>lenB)
        {
            headA = headA->next;
            lenA--;
        }
        while(lenB>lenA)
        {
            headB = headB->next;
            lenB--;
        }
        while(headA!=NULL && headB!=NULL)
        {
            if(headA==headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};