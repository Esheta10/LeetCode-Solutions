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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
            return 0;

        queue<pair<TreeNode*,ll>> que;
        que.push({root,0}); // {root,uska_index}

        ll maxWidth = 0;

        while(!que.empty()){

            ll L = que.front().second;
            ll R = que.back().second;

            maxWidth = max(maxWidth, R - L + 1);

            int n = que.size();

            while(n--){

                TreeNode* node = que.front().first;
                ll idx = que.front().second;
                que.pop();

                if(node->left != NULL)
                    que.push({node->left, 2*idx+1});

                if(node->right != NULL)
                    que.push({node->right, 2*idx+2});
            }
        }
        return maxWidth;
    }
};