/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // bool isOnePresent(TreeNode* root){

    //     if(root == NULL)
    //         return false;

    //     if(root->val == 1)
    //         return true;

    //     return isOnePresent(root->left) || isOnePresent(root->right);   // kisi ek bhi subtree mein agar 1 mil gaya toh thik hai
    // }
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root == NULL)
            return NULL;

        // Post-order traversal
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        // if(!isOnePresent(root->left)) // agar root ke left mein 1 nahi mila toh usko null set kardo
        //     root->left = NULL;

        // if(!isOnePresent(root->right))// agar root ke right mein 1 nahi mila toh usko null set kardo
        //     root->right = NULL;

        // if(!isOnePresent(root->left) && !isOnePresent(root->right) && root->val == 0)// agar root ke left aur right dono mein null hai and root khud bhi 0 hai then null set kardo

        if(root->left == NULL && root->right == NULL && root->val == 0)
            return NULL;

        return root;
    }
};