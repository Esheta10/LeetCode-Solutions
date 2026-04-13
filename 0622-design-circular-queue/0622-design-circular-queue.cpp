class MyCircularQueue {
private:
    vector<int> arr;
    int front, rear, count, capacity;
public:
    MyCircularQueue(int k) {
        
        capacity = k;
        arr.resize(k);
        front = -1;
        rear = -1;
        count = 0;
    }
    
    bool enQueue(int value) {
        
        if(isFull())
            return false;
        
        if(isEmpty())
            front = rear = 0;
        else 
            rear = (rear + 1) % capacity;

        arr[rear] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        
        if(isEmpty())
            return false;

        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;

        count--;
        return true;
    }
    
    int Front() {
        
        return isEmpty() ? -1 : arr[front];
    }
    
    int Rear() {

        return isEmpty() ? -1 : arr[rear]; 
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */