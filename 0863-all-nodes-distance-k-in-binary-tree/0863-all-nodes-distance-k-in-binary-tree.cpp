/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    // STEP-1: Build parent map
    void addParent(TreeNode* root){

        if(root == NULL)
            return;

        if(root->left != NULL)
            parent[root->left] = root;

        addParent(root->left);

        if(root->right != NULL)
            parent[root->right] = root;

        addParent(root->right);      
    }
    // STEP-2: BFS to find k distance nodes
    void collectKDistanceNodes(TreeNode* target, int k, vector<int>& result){
        
        queue<TreeNode*> que;
        que.push(target);

        //Visited set: kaun se nodes already visis ho chuke hain
        unordered_set<int> visited;
        visited.insert(target->val);

        while(!que.empty()){

            int n = que.size();

            if(k==0)
                break; // matlab k distance pahunch chuke hain

                while(n--){

                    TreeNode* node = que.front();
                    que.pop();

                    //Direction 1: left child
                    if(node->left != NULL && visited.find(node->left->val) == visited.end()){
                    // matlab agar left child hai and woh visited nahi hai
                            que.push(node->left);
                            visited.insert(node->left->val);
                    }

                    //Direction 2: right child
                    if(node->right != NULL && visited.find(node->right->val) == visited.end()){
                        // matlab agar right child hai and woh visited nahi hai
                        que.push(node->right);
                        visited.insert(node->right->val);
                    }

                    //Direction 3: Parent(upar) ki taraf
                    if(parent.find(node) != parent.end() && visited.find(parent[node]->val) == visited.end()){
                        // agar parent hai aur visited nahi hai

                        que.push(parent[node]);
                        visited.insert(parent[node]->val);
                    }
                }
            k--;
        }
          while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();

            result.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> result;

        addParent(root);

        collectKDistanceNodes(target, k, result);

        return result;
    }
};