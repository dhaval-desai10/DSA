#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, max;
    int* queue;
public:
    Queue(int c) {
        front = rear = 0;
        max = c;
        queue = new int;
    }

    void enqueue(int data) {
        if (max == rear) {
            cout << "Queue is full\n";
            return;
        } else {
            queue[rear] = data;
            rear++;
        }
    }

    void dequeue() {
        if (front == rear) {
            cout << "Queue is empty\n";
            return;
        } else {
            for (int i = 0; i < rear - 1; i++) {
                queue[i] = queue[i + 1];
            }
            rear--;
        }
    }

    void display() {
        if (front == rear) {
            cout << "Queue is empty\n";
            return;
        }

        for (int i = front; i < rear; i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); 

    q.dequeue();
    q.display(); 

    return 0;
}