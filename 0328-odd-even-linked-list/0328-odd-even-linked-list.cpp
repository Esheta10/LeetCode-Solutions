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
    ListNode* oddEvenList(ListNode* head) {
         if(head == NULL || head->next == NULL)
            return head;
        
        
        /*
            Story : 
            1. Hume odd and even ko segregate karna hai
            2. To let's take two pointers to point to odd and even nodes
            3. Unko alag alag segregate kardenge
            4. Last me connect kardenge odd ko even se
            
        */
        ListNode *odd = head;
        ListNode *even = head->next;
        
        ListNode* evenStart = head->next;

        while(even!=NULL && even->next!=NULL)
        {
            odd->next=even->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;

        }
        odd->next=evenStart;
        return head;
    }
};