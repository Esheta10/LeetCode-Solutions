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
    int getDiff(ListNode* headA, ListNode* headB){

        int lenA = 0, lenB = 0;
        while(headA != NULL){
            lenA++;
            headA = headA->next;
        }
        while(headB != NULL){
            lenB++;
            headB = headB->next;
        }
        return lenA - lenB;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == NULL || headB == NULL)
            return NULL;

        int d = getDiff(headA, headB);

        if(d > 0){
            while(d--)
                headA = headA->next;
        } else {
            while(d++)
                headB = headB->next;
        }

        while(headA != NULL && headB != NULL){

            if(headA == headB)
                return headA;

            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};