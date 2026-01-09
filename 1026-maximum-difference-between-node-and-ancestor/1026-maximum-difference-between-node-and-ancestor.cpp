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
    int maxDiff;
    void findMaxUtil(TreeNode* root, TreeNode* child){

        if(root==NULL || child==NULL)
            return;

        maxDiff = max(maxDiff, abs(root->val - child->val));

        findMaxUtil(root,child->left);
        findMaxUtil(root,child->right);
    }
    void findMaxDiff(TreeNode* root){

        if(root == NULL || root->left == NULL && root->right == NULL)
            return;

        // find max diff of this root with all its children
        findMaxUtil(root,root->left);
        findMaxUtil(root,root->right);


        // further move left and right
        findMaxDiff(root->left);
        findMaxDiff(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        
        maxDiff = INT_MIN;
        findMaxDiff(root);

        return maxDiff;
    }
};