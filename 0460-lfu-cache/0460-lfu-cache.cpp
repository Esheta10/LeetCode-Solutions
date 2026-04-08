class LFUCache {
public:
    // Node
    struct Node{
        int key, val, freq;
        Node *prev;
        Node *next;
        Node(int k, int v){
            key = k;
            val = v;
            freq = 1;
            prev = NULL;
            next = NULL;
        }
    };
    // FreqBucket -> DLL acting as an LRU list for given frequency
    // [HEAD] <-> [most recent] <-> ..............<-> [least recent] <-> [TAIL]
    struct FreqBucket{
        Node *head;
        Node *tail;
        int size;

        FreqBucket(){
            size = 0;

            head = new Node(0,0);
            tail = new Node(0,0);

            head->next = tail;
            tail->prev = head;
        }
        
        // remove node, wherever it is
        void remove(Node *node){

            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        // place node right after head = mark as Most Recently Used
        void insertFront(Node *node){

            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;
            size++;
        }

        // Node just before tail = Least Recently Used
        Node *lruNode(){
            return tail->prev;
        }
        bool isEmpty(){
            return size==0;
        }
    };

    // Cache state
    int capacity;
    int minFreq;
    unordered_map<int, Node*> keyMap;
    unordered_map<int, FreqBucket*> freqMap;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 1;
    }
    
    // Returns bucket for given frequency, creating it, if needed
    FreqBucket *getBucket(int freq){

        if(freqMap.find(freq) == freqMap.end()){
            freqMap[freq] = new FreqBucket();
        } 
        return freqMap[freq];
    }
    // promote
    // Moves node from freqMap[f] to freqMap[f+1]
    void promote(Node *node){

        // Step-1: Find which bucket the node currently lives in
        int oldFreq = node->freq;
        FreqBucket* oldBucket = getBucket(oldFreq);

        // Step-2: Remove the node from that bucket
        oldBucket->remove(node);

        // Step-3: If that bucket is now empty and was the lowest frequency bucket, update minFreq to the next frequency
        bool oldBucketIsNowEmpty = oldBucket->isEmpty();
        bool wasTheMinimumBucket = (oldFreq == minFreq);

        if(oldBucketIsNowEmpty && wasTheMinimumBucket)
            minFreq++;

        // Step-4: Increment the node's frequency
        int newFreq = oldFreq + 1;
        node->freq = newFreq;

        //Step-5: Find the newBucket and insert the node at front
        FreqBucket *newBucket = getBucket(newFreq);
        newBucket->insertFront(node);
    }

    int get(int key) {

        if(keyMap.find(key) == keyMap.end())
            return -1;

        // promote the node -> it's frequency goes up and return its value
        Node *node = keyMap[key];
        promote(node);
        return node->val;    
    }
    
    void put(int key, int value) {
        
        if(capacity <= 0)
            return;

        //Case-1: Key already exists, update the value and promote
        if(keyMap.find(key) != keyMap.end()){

            Node* existingNode = keyMap[key];
            existingNode->val = value;
            promote(existingNode);
            return;
        }

        //Case-2: Cache is full -> evict the LRU node from minFreq Bucket
        bool cacheIsFull = ((int)keyMap.size() == capacity);

        if(cacheIsFull){

            FreqBucket *minBucket = getBucket(minFreq);
            Node *nodeToEvict = minBucket->lruNode();
            minBucket->remove(nodeToEvict);
            keyMap.erase(nodeToEvict->key);
            delete nodeToEvict;
        }
        

        //Case-3: Insert the new Node
        // New nodes always start at freq=1 , so reset minFreq to 1

        Node *freshNode = new Node(key, value);
        keyMap[key] = freshNode;
        minFreq = 1;
        FreqBucket *firstBucket = getBucket(1);
        firstBucket->insertFront(freshNode);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */