#include <iostream>
using namespace std;

class outre {
    int front;
    int rear;
    int size;
    int* arr;

public:
    outre(int n) {
        front = -1;
        rear = -1;
        size = n;
        arr = new int[n];
    }

    void insertfront(int data) {
        // full
        if ((front == 0 && rear == size - 1) || (front== rear + 1)) {
            cout << "its OverFlow " << endl;
        }
        else if (front == -1) { // empty
            front = rear = 0;
            arr[front] = data;
        }
        else if (front == 0) {
            front = size - 1;
            arr[front] = data;
        }
        else {
            front = front - 1;
            arr[front] = data;
        }
            cout<<" inserted data is : "<< arr[front]<<endl;
    }

    void insertend(int data) {
        // full
        if ((front == 0 && rear == size - 1) || (front== rear + 1)) {
            cout << "its OverFlow " << endl;
        }
        else if (front == -1) { // empty
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1) {
            rear = 0;
            arr[rear] = data;
        }
        else {
            rear = rear + 1;
            arr[rear] = data;
        }
            cout<<" inserted data is : "<< arr[rear]<<endl;
    }

    void deletone() {
        if (front == -1) { // empty
            cout << " its UnderFlow " << endl;
        }
        else {
            cout << "removed is : " << arr[front] << endl;
            if (front == rear) {
                front = rear = -1;
            }
            else if (front == size - 1) {
                front = 0;
            }
            else {
                front = front + 1;
            }
        }
    }
};

int main() {
    outre q(5);
    
    q.insertend(2);
    q.insertend(4);
    q.deletone();

    return 0;
}