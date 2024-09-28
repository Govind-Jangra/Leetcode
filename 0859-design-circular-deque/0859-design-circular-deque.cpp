class MyCircularDeque {
public:
    int start, size, cap;
    vector<int> arr;
    MyCircularDeque(int k) {
        arr = vector<int>(k);
        start = size = 0;
        cap = k;
    }

    bool insertFront(int value) {
        if (size == cap) return false;
        arr[start] = value;
        start = (start - 1 + cap) % cap; 
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (size == cap) return false;
        size++;
        arr[(start+size)%cap] = value;
        return true;
    }
    
    bool deleteFront() {
        if (size == 0) return false;
        start = (start + 1) % cap;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (size == 0) return false;
        size--;
        return true;
    }
    
    int getFront() {
        if (size == 0) return -1;
        return arr[(start+1)%cap];
    }
    
    int getRear() {
        if (size == 0) return -1;
        return arr[(start+size+cap)%cap];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};