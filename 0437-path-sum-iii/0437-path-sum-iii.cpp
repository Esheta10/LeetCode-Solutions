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
    void solve(TreeNode* root, int &targetSum, int &count, long long currSum, unordered_map<long long, int>& mp){
        
        if(root == NULL)
            return;

        currSum += root->val;
        if(mp.find(currSum-targetSum) != mp.end()){
            count += mp[currSum-targetSum];
        }

        mp[currSum]++;
        solve(root->left, targetSum, count, currSum, mp);
        solve(root->right, targetSum, count, currSum, mp);

        mp[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        int count = 0;
        unordered_map<long long,int> mp;
        mp[0] = 1;


        solve(root, targetSum, count, 0, mp); // 0 denotes currSum
        return count;
    }
};