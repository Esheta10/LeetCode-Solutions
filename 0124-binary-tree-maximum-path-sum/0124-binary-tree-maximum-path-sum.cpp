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
    int maxSum;
    int totalSum(TreeNode* root){

        if(root==NULL)
            return 0;

        int l = totalSum(root->left);
        int r = totalSum(root->right);

        int neeche_hi_mil_gaya_answer = l + r + root->val;
        int dono_mein_se_koi_ek_acha = max(l,r) + root->val; // 2
        int only_root_acha = root->val; // 3


        maxSum = max({maxSum,neeche_hi_mil_gaya_answer, dono_mein_se_koi_ek_acha,only_root_acha});
        
        // most important part ->  return keval 2 and 3 karenge
        return max(dono_mein_se_koi_ek_acha,only_root_acha);
    }
    int maxPathSum(TreeNode* root) {
        
        maxSum = INT_MIN;

        totalSum(root);

        return maxSum;
    }
};