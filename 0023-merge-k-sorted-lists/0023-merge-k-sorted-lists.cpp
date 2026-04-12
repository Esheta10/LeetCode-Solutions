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
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2){

        if(l1 == NULL)
            return l2;
        
        if(l2 == NULL)
            return l1;

        ListNode* result;
        if(l1->val <= l2->val){
            result = l1;
            result->next = mergeTwoSortedLists(l1->next, l2);
        } else {
            result = l2;
            result->next = mergeTwoSortedLists(l1, l2->next);
        }
        return result;
    }
    ListNode* partitionAndMerge(int l, int r, vector<ListNode*>& lists){

        if(l==r)
            return lists[l];
            
        if(l > r)
            return NULL;

        int mid = l + (r-l)/2;
        ListNode* l1 =  partitionAndMerge(l,mid,lists);
        ListNode* l2 =  partitionAndMerge(mid+1,r,lists);

        return mergeTwoSortedLists(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();

        return partitionAndMerge(0, n-1, lists);
    }
};