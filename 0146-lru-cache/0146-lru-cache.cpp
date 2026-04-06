class LRUCache {
public:
    // Node Definition
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    // Constructor
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        // head <-> tail
        head->next = tail;
        tail->prev = head;
    }
    // ----------------------------------remove Node--------------------------------------------
    // Detaches a node from where it sits in the list and stitches its left & right neighbours together
    //  Before:  ... ↔ [prev] ↔ [node] ↔ [next] ↔ ...
    //  After:   ... ↔ [prev] ↔ [next] ↔ ...
    void removeNode(Node* node){

       node->prev->next = node->next;
       node->next->prev = node->prev;
    }
    // -----------------------------------insert At Front------------------------------------------
    // Inserts a node immediately after head(MRU Position) 
    // Must be called after removeNode, if removing an existing Node
    //  Before:  HEAD ↔ [first] ↔ ...
    //  After:   HEAD ↔ [node] ↔ [first] ↔ ...
    void insertAtFront(Node* node){

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }
    //----------------------------------------get-----------------------------------------------------
    // Returns value for key, or -1 if not found
    // On hit: moves the node to front(MRU Position) 
    int get(int key) {
        
        // key doesn't exist in cache
        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        //move to Front = mark as Most Recently Used 
        removeNode(node);
        insertAtFront(node);

        return node->val;
    }
    // ---------------------------------put----------------------------------------------
    // Insert or updates a key-value pair
    // Always places the node at MRU position (front)
    // If cache is full, evicts the LRU node

    void put(int key, int value) {
        
        // Case-1 : Key already exists-> update the value and move to front
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;  // update value in place
            removeNode(node);   // detach at current position
            insertAtFront(node);    // re-attach at MRU position
            return;
        }

        // Case-2: Key is new and cache is full-> evict LRU first
        if(mp.size() == capacity){
            Node* lru = tail->prev;

            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        // Case-3: Insert new Node at front( MRU position )
        Node* newNode = new Node(key, value);
        insertAtFront(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */