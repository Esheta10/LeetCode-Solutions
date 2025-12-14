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
    int pairSum(ListNode* head) {
        
        //Approach-1 (Using vector/array)
        vector<int> vec;

        // while(head){
        //     vec.push_back(head->val);
        //     head=head->next;
        // }
        // int i=0, j=vec.size()-1;
        // int result=0;
        // while(i<j){
        //     result = max(result, vec[i]+vec[j]);
        //     i++;
        //     j--;
        // }
        // return result;

        //Approach-2 (Using stack)
        // stack<int> st;
        // ListNode* curr = head;

        // while(curr){
        //     st.push(curr->val);
        //     curr = curr->next;
        // }
        // curr = head;
        // int count = 1;
        // int N = st.size();
        // int result = 0;

        // while(count <= N/2){
        //     result = max(result, st.top() + curr->val);
        //     curr = curr->next;
        //     st.pop();
        //     count++;
        // }
        // return result;

        //Approach-3(Reversing the 2nd half of Linked List)

        //3.a Find the middle node of Linked List
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow;

        //3.b Reversing Part
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        while(mid){

            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;

        }

        //3.c Reversing Part
        ListNode* curr = head;
        int result = 0;
        while(prev){
            result = max(result, prev->val + curr->val);
            prev = prev->next;
            curr = curr->next;
        }

        return result;
    }
};