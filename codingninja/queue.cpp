#include <bits/stdc++.h> 
class Queue {
    int* arr;
    int rear;
    int qfront;
    int size;
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        rear = qfront = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(rear == qfront) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == size) {
            return;
        }
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear == qfront) {
            rear = qfront = 0;
            return -1;
        }
        else{
            int value = arr[qfront];
            qfront++;
            return value;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront == rear)
            return -1;
        else
            return arr[qfront];
    }
};