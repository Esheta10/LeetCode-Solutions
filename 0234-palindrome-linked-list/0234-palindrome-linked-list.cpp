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
    bool isPalindrome(ListNode* head) {
       vector<int> temp;

       ListNode* curr = head;
       while(curr)
       {
        temp.push_back(curr->val);
        curr=curr->next;
       } 
       int i=0;
       int j=temp.size()-1;
       while(i<j)
       {
            if(temp[i]!=temp[j])
            {
                return false;
            }
            i++;
            j--;
       }
       return true;
    }
};