class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        // Step-1: Parent count karo
        vector<int> parentCount(n,0);

        for(int i=0;i<n;i++){
            
            if(leftChild[i] != -1)
                parentCount[leftChild[i]]++;

            if(rightChild[i] != -1)
                parentCount[rightChild[i]]++;

        }

        // Step-2: Root dhundho aur validate karo
        int root = -1;
        for(int i=0;i<n;i++){
            if(parentCount[i] == 0){ // check: kya iss node ka koi parent nahi hai?
                if(root != -1)  // agar pehle se root mil chuka hai
                    return false; // multiple roots = invalid

                root = i; // iss node ko root bana do
            }
            if(parentCount[i] > 1)
                return false; // multiple parents = invalid
        }
        
        
        if(root == -1)  // Agar koi root hi nahi mila
            return false;

        // Step-3: BFS se saare nodes visit karo
        queue<int> que;
        que.push(root);

        unordered_set<int> visited;
        visited.insert(root);


        while(!que.empty()){

            int node = que.front();
            que.pop();

            if(leftChild[node] != -1){
                if(visited.find(leftChild[node]) == visited.end()){
                    que.push(leftChild[node]);
                    visited.insert(leftChild[node]);
                } else {
                    return false; // cycle detected
                }
            }

            if(rightChild[node] != -1){
                if(visited.find(rightChild[node]) == visited.end()){
                    que.push(rightChild[node]);
                    visited.insert(rightChild[node]);
                } else {
                    return false; // cycle detected
                }
            }
        }
        //Step-4: saare nodes visit hue hain
        return visited.size()==n;
    }
};