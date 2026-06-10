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
    bool findNodes(TreeNode* root, int sum, int &targetSum){

        if(root == NULL)
            return false;

        sum += root->val;
        if(root->left == NULL && root->right == NULL){

            if(sum == targetSum)
                return true;

            return false;
        }

        bool leftSide = findNodes(root->left, sum, targetSum);
        bool rightSide = findNodes(root->right, sum, targetSum);

        return leftSide || rightSide;
   }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int sum = 0;

        bool result = findNodes(root, sum, targetSum);

        return result;
    }
};