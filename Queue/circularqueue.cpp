#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, size;

public:
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int data) {
        if ((front == 0 && rear == size - 1) || front == rear +1 ) {
            cout << "its full" << endl;
        }
        else if (front == -1) {
            rear = front = 0;
            arr[rear] = data;
            cout << "pushed: " << arr[rear] << endl; // Print the first enqueued element
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = data;
            cout << "pushed: " << arr[rear] << endl; // Print the enqueued element
        }
        else {
            rear++;
            arr[rear] = data;
            cout << "pushed: " << arr[rear] << endl;
        }
    }
    
    void dequeue() {
        if (front == -1) {
            cout << "its empty " << endl;
        }
        else {
            cout << arr[front] << " is popped: " << endl;
            if (front == rear) {
                front = rear = -1;
            }
            else if (front == size - 1) {
                front = 0;
            }
            else {
                front++;
            }
        }
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);

    return 0;
}