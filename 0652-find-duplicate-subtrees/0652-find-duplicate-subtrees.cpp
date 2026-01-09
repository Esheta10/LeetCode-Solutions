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
    string dfs(TreeNode* root, unordered_map<string,int>& mp,vector<TreeNode*>& res){

        if(root == NULL)
            return "NULL";

        string s = to_string(root->val) + "," + dfs(root->left,mp,res) + "," + dfs(root->right,mp,res);

        if(mp[s] == 1)  // jab pehli baar mile toh mp[s] = 0 se 1 hota hai, jab dusri baar mile, matlab when mp[s]==1 already, tab result mein daalo
            res.push_back(root);        

        mp[s]++;

        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        unordered_map<string,int> mp;

        vector<TreeNode*> res;

        dfs(root,mp,res);

        return res;
    }
};