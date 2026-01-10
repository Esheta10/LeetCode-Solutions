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
    int maxLevelSum(TreeNode* root) {
        
        int maxSum = INT_MIN;
        int currentLevel = 1;
        int resultLevel = 0;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){

            int n = que.size();
            int sum = 0;

            while(n--){
                TreeNode* node = que.front();
                que.pop();
                
                sum += node->val;

                if(node->left != NULL)
                    que.push(node->left);

                if(node->right != NULL)
                    que.push(node->right);
            }

            if(sum > maxSum){
                maxSum = sum;
                resultLevel = currentLevel;
            }
            currentLevel++;
        } 
        return resultLevel;
    }
};