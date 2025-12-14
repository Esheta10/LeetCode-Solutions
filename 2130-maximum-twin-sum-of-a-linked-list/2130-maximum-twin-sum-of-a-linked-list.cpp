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
        // vector<int> vec;

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
        stack<int> st;
        ListNode* curr = head;

        while(curr){
            st.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        int count = 1;
        int N = st.size();
        int result = 0;

        while(count <= N/2){
            result = max(result, st.top() + curr->val);
            curr = curr->next;
            st.pop();
            count++;
        }
        return result;
    }
};