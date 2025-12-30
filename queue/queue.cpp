class MyCircularQueue {
    int *arr;
    int k, currSize;
    int f,r;
public:
    MyCircularQueue(int k) {
        this->k = k;
        arr = new int[k];
        currSize = 0;
        f = r = -1;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }

        if(currSize == 0) {
            f = r = 0;
        } else {
            r = (r + 1) % k;
        }

        
        arr[r] = value;
        currSize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }

        if(currSize == 1) {
            f = r = -1;
        } else {
            f = (f + 1) % k;
        }

        
        currSize--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) {
            return -1;
        }
        return arr[f];
    }
    
    int Rear() {
        if(isEmpty()) {
            return -1;
        }
        return arr[r];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return k == currSize;
    }
};

