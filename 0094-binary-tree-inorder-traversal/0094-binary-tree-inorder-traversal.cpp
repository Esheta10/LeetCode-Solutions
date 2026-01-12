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
    // void inOrder(TreeNode* root, vector<int>& result){

    //     if(root == NULL)
    //         return;

    //     inOrder(root->left,result);
    //     result.push_back(root->val);
    //     inOrder(root->right,result);
    // }
    vector<int> inorderTraversal(TreeNode* root) {

        // Approach-1
        // vector<int> result;

        // inOrder(root,result);

        // return result;

        // Approach-2: Morris Inorder Traversal
        //T.C : O(n)
        //S.C : O(1)

        if(root == NULL)
            return {};

        vector<int> result;

        TreeNode* curr = root;

        while(curr != NULL){

            if(curr->left == NULL){
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* leftChild = curr->left;

                while(leftChild->right != NULL){

                    leftChild = leftChild->right;
                }

                leftChild->right = curr;
                // curr->left ko app NULL set kar sakte ho
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            
            }
        }
        return result;
    }
};