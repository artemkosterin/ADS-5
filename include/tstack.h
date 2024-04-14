#ifndef TSTACK_H
#define TSTACK_H

template <typename T, int size>
class TStack {
private:
    T *stackArray;
    int topIndex;
public:
    TStack() {
        stackArray = new T[size];
        topIndex = -1;
    }
    
    ~TStack() {
        delete[] stackArray;
    }
    
    void push(T value) {
        if (topIndex < size - 1) {
            topIndex++;
            stackArray[topIndex] = value;
        }
    }
    
    void pop() {
        if (topIndex >= 0) {
            topIndex--;
        }
    }
    
    T top() const {
        if (topIndex >= 0) {
            return stackArray[topIndex];
        }
        throw std::out_of_range("Stack is empty");
    }
    
    bool isEmpty() const {
        return topIndex == -1;
    }
    
    bool isFull() const {
        return topIndex == size - 1;
    }
};

#endif
