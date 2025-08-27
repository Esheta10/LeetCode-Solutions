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
    ListNode* mergeTwoSortedLists(ListNode* lists1, ListNode* lists2)
    {
        if(lists1==NULL)
            return lists2;
        if(lists2==NULL)
            return lists1;

        if(lists1->val < lists2->val)
        {
            lists1->next = mergeTwoSortedLists(lists1->next,lists2);
            return lists1;
        }
        else
        {
            lists2->next = mergeTwoSortedLists(lists2->next,lists1);
            return lists2;
        }
        return NULL;
    }
    ListNode* partitionMerge(int start,int end,vector<ListNode*>& lists)
    {
        if(start >  end)
            return NULL;
        if(start==end)
            return lists[start];

        int mid = start + (end-start)/2;
        ListNode* l1 = partitionMerge(start,mid,lists);
        ListNode* l2 = partitionMerge(mid+1,end,lists);

        return mergeTwoSortedLists(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k==0)
            return NULL;

        return partitionMerge(0,k-1,lists);
    }
};