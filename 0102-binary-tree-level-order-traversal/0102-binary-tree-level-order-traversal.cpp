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
    vector<vector<int>> levelOrder(TreeNode* root) {
    if(root==NULL)
            return {};

    vector<vector<int>> result;
    queue<TreeNode*> que;
    que.push(root);

    while(!que.empty())
    {
        int n = que.size();
        vector<int> level;

        while(n--)
        {
            TreeNode* node = que.front();
            que.pop();

            level.push_back(node->val);
            if(node->left!=NULL)
                que.push(node->left);
            if(node->right!=NULL)
                que.push(node->right);
        }
        result.push_back(level);
    }
    return result;
    }
};