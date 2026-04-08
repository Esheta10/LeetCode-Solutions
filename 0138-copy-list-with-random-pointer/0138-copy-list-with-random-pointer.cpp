/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL)
            return head;

        unordered_map<Node*, Node*> mp;

        Node* curr = head;
        while(curr){

            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr != NULL){

            Node* clone = mp[curr];

            if(curr->next != NULL){
                clone->next = mp[curr->next];
            }

            if(curr->random != NULL){
                clone->random = mp[curr->random];
            }
            curr = curr->next;
        }
        return mp[head];
    }
};