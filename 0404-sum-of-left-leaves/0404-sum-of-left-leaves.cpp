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
    int solve(TreeNode* curr,TreeNode* root)
    {
        if(curr==NULL)
            return 0;
        
        int left = solve(curr->left,curr);
        int right = solve(curr->right,curr);

        int sum = 0;
        if(curr->left==NULL && curr->right==NULL)//leafnode
        {
            if(root!=NULL && root->left==curr)
                sum += curr->val;
        }
        return left+right+sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        return solve(root,NULL);
    }
};