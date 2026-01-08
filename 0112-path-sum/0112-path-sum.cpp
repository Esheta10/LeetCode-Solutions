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
    
    bool fill(TreeNode* root, int sum, int& targetSum){

        if(root == NULL)
            return false;

        sum += root->val;

        if(root->left==NULL && root->right==NULL){
            if(sum == targetSum)
                return true;
        }
           
        return fill(root->left,sum,targetSum) || fill(root->right,sum,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int sum = 0;
        return fill(root,sum,targetSum);
        
    }
};