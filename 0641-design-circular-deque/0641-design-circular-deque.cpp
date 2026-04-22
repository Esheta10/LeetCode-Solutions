class MyCircularDeque {
private:
    vector<int> deq;
    int front, rear, capacity, size;
public:
    MyCircularDeque(int k) {
        
        capacity = k;
        deq = vector<int>(capacity);
        front = -1;
        rear = -1;
        size = 0;
    }
    
    bool insertFront(int value) {
        
        if(isFull())
            return false;
        
        if(isEmpty()){
            front = rear = 0;
        } else {

            front = (front - 1 + capacity) % capacity;
        }
        deq[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        
        if(isFull())
            return false;
        if(isEmpty()){
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        deq[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        
        if(isEmpty())
            return false;
        if(front == rear){
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        
        if(isEmpty())
            return false;

        if(front == rear){
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
        return true;
    }
    
    int getFront() {
        
        return isEmpty() ? -1 : deq[front];
    }
    
    int getRear() {
        
        return isEmpty() ? -1 : deq[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        
        return (rear + 1) % capacity == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */