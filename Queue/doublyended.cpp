#include <iostream>
using namespace std;

class Deque {
    int front;
    int rear;
    int n;
    int *arr;

public:
    Deque(int size) {
        front = -1;
        rear = -1;
        n = size;
        arr = new int[n];
    }
    
    void insertFront(int data) {
        if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
            cout << "Deque is full" << endl;
        } else {
            if (front == -1) { // First element insertion
                front = 0;
                rear = 0;
            } else if (front == 0) {
                front = n - 1;
            } else {
                front--;
            }
            arr[front] = data;
            cout << "Data inserted at front: " << arr[front] << endl;
        }
    }

    void insertRear(int data) {
        if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
            cout << "Deque is full" << endl;
        } else {
            if (rear == -1) { // First element insertion
                front = 0;
                rear = 0;
            } else if (rear == n - 1) {
                rear = 0;
            } else {
                rear++;
            }
            arr[rear] = data;
            cout << "Data inserted at rear: " << arr[rear] << endl;
        }
    }

    void deleteFront() {
        if (front == -1) {
            cout << "Deque is empty" << endl;
        } else {
            cout << "Data deleted from front: " << arr[front] << endl;
            if (front == rear) { // Only one element
                front = -1;
                rear = -1;
            } else if (front == n - 1) {
                front = 0;
            } else {
                front++;
            }
        }
    }

    void deleteRear() {
        if (rear == -1) {
            cout << "Deque is empty" << endl;
        } else {
            cout << "Data deleted from rear: " << arr[rear] << endl;
            if (front == rear) { // Only one element
                front = -1;
                rear = -1;
            } else if (rear == 0) {
                rear = n - 1;
            } else {
                rear--;
            }
        }
    }

    int getFront() {
        if (front == -1) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (rear == -1) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(1);
    dq.insertRear(2);
    dq.insertFront(3);
    dq.insertFront(4);
    dq.insertRear(5);

    dq.deleteFront();
    dq.deleteRear();

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    return 0;
}