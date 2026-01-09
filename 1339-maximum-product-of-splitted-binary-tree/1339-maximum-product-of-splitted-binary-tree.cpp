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
    long M = 1e9+7;
    long maxP = 0;
    long SUM = 0;
    int totalSum(TreeNode* root){

        if(root == NULL)
            return 0;

        int leftSum = totalSum(root->left);
        int rightSum = totalSum(root->right);
        int sum = root->val + leftSum + rightSum;

        return sum;
    }
    int find(TreeNode* root){

        if(root == NULL)
            return 0;

        int leftSubtreeSum = find(root->left);
        int rightSubtreeSum = find(root->right);
        long subtreeSum = root->val + leftSubtreeSum + rightSubtreeSum;

        long remainingSubtreeSum = SUM - subtreeSum;

        maxP = max(maxP, subtreeSum*remainingSubtreeSum);

        return subtreeSum; 
    }
    int maxProduct(TreeNode* root) {
        if(root == NULL)
            return 0;

       SUM = totalSum(root);

        find(root);

        return maxP % M;
    }
};