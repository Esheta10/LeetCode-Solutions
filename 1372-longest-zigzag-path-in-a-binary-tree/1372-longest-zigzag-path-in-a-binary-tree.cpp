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
    int maxPath = 0;
    void solve(TreeNode* root,int steps, bool goLeft){
        if(root == NULL)
            return;

        maxPath = max(maxPath,steps);

        if(goLeft==true){
            solve(root->left,steps+1,false); // here false denotes goRight, if ware going left as expected then increase the steps and next go right
            solve(root->right,1,true); // here true denotes goLeft, if not going in the intended direction, reset the step-count from 1 
        } else {
            solve(root->right,steps+1,true); // true means now goLeft
            solve(root->left,1,false);
        }
    }
    int longestZigZag(TreeNode* root) {
        
        solve(root,0,true); // goLeft
        solve(root,0,false);    // goRight

        return maxPath;
    }
};