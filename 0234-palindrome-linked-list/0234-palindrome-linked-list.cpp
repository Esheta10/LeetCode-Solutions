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
    ListNode* reverseList(ListNode* head){

        if(head==NULL || head->next==NULL)
            return head;

        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    bool isPalindrome(ListNode* head) {
        //Approach-1 (Using extra space)
        //T.C : O(n)
        //S.C : O(n)    
        // ListNode* curr = head;
        // vector<int> temp;

        // while(curr){
        //     temp.push_back(curr->val);
        //     curr = curr->next;
        // }

        // int i=0;
        // int j = temp.size()-1;

        // while(i<j){
        //     if(temp[i] != temp[j])
        //         return false;

        //     i++;
        //     j--;
        // }
        // return true;

        if(head==NULL || head->next==NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast!=NULL && fast->next!=NULL){

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revHead = reverseList(slow);
        prev->next = NULL;

        while(revHead!=NULL && head!=NULL){

            if(revHead->val != head->val)
                return false;

            revHead = revHead->next;
            head = head->next;
        }
        return true;
    }
};