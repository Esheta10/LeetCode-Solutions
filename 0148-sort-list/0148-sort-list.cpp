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
    ListNode* getMiddle(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!= NULL && fast->next != NULL){

            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1, ListNode* l2){

        if(l1 == NULL)
            return l2;

        if(l2 == NULL)
            return l1;

        ListNode* result;
        if(l1->val < l2->val){

            result = l1;
            result->next = merge(l1->next, l2);
        } else {

            result = l2;
            result->next = merge(l1, l2->next);
        }
        return result;
    }
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* mid = getMiddle(head);
        ListNode* rightHalf = mid->next;
        mid->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHalf);

        return merge(left, right);
    }
};