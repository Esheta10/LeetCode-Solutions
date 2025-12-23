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
//Approach (Using Simple straight forward approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
      
      if(head == NULL) return NULL;

      unordered_set<int> st(nums.begin(),nums.end());

      //Handle the head
      while(head!=NULL && st.find(head->val) != st.end()){
        // ListNode* temp = head;
        head = head->next;
        // delete(temp);   // deleting the hanging node
      }

      ListNode* curr = head;
      while(curr != NULL && curr->next != NULL){
        if(st.find(curr->next->val) != st.end()){
            ListNode* temp = curr->next;
            curr->next = curr->next->next;  // curr->next is updated
            delete(temp);   // Deleting Hanging Node
        } else {
            curr = curr->next;
        }
      }
      return head;
    }
};
