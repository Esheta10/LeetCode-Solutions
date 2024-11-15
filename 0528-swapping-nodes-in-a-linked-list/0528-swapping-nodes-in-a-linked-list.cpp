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
//Approach-1 (Making use of length of LinkedList)
/*
    int findLength(ListNode* head)
    {
        int l=0;
        while(head)
        {
            head=head->next;
            l++;
        }
        return l;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        //kth node from start
        //kth node from end = Length-k+1 node from beginning
        int Length = findLength(head);

        int k_1 = k;
        ListNode* temp1 = head;
        while(k_1 > 1)
        {
            temp1=temp1->next;
            k_1--;
        }
        ListNode* temp2 = head;
        int k_2 = Length-k+1;
        while(k_2 > 1)
        {
            temp2=temp2->next;
            k_2--;
        }
        swap(temp1->val,temp2->val);
        return head;*/

        //Approach-2 (Using only One Pass)
        ListNode* swapNodes(ListNode* head, int k) {
            ListNode* p1=NULL;
            ListNode* p2=NULL;

            ListNode* temp=head;
            while(temp)
            {
                if(p2!=NULL)
                    p2=p2->next;
                k--;
                if(k==0)
                {
                    p1=temp;
                    p2=head;
                }
                temp=temp->next;
            }
        swap(p1->val,p2->val);
        return head;
    }
};