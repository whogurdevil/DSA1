#include <bits/stdc++.h> 
class CircularQueue{
    int* arr;
    int front;
    int rear;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        rear = front = -1;
        arr = new int[size];
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Full queue check
        if((rear + 1) % size == front){
            return false;
        }
        // Empty queue (first push)
        else if(front == -1){
            rear = front = 0;
        }
        // Circular operation
        else if(rear == size-1 && front != 0) {
            rear = 0;
        }
        // Normal operation
        else {
            rear = (rear + 1) % size;
        }
        
        // Push
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Empty queue check
        if(front == -1){
            return -1;
        }

        // Save the arr[front]
        int value = arr[front];
        arr[front] = -1;

        // Single element is present
        if(front == rear){
            rear = front = -1;
        }
        // Normal operation
        else if(front == size-1){
            front = 0; 
        }
        else{
            front = (front + 1) % size;
        }

        return value;
    }
};
