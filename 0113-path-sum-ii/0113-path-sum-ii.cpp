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
    vector<vector<int>> result;
    void findNodes(TreeNode* root, int sum, vector<int> temp, int &targetSum){

        if(root == NULL)
            return;

        sum += root->val;
        temp.push_back(root->val);

        // reach leaf then check
        if(root->left == NULL && root->right == NULL){

                if(sum == targetSum){
                    result.push_back(temp);
                }
                return;
        }

        findNodes(root->left, sum, temp, targetSum);
        findNodes(root->right,sum, temp, targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL)
            return {};
        
        vector<int> temp;
        int sum = 0;
        findNodes(root, sum, temp, targetSum);

        return result;
    }
};