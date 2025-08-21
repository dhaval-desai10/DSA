#include <iostream>
using namespace std;

class inre {
    int front;
    int rear;
    int size;
    int* arr;

public:
    inre(int n) {
        front = -1;
        rear = -1;
        size = n;
        arr = new int[n];
    }

    void insertone(int data) {
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    void deletstart() {
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

    void deletend() {
        if (front == -1) { // empty
            cout << " its UnderFlow " << endl;
        }
        else {
            cout << "removed is : " << arr[rear] << endl;
            if (front == rear) {
                front = rear = -1;
            }
            else if (rear == 0) {
                rear = size - 1;
            }
            else {
                rear = rear - 1;
            }
        }
    }
};

int main() {
    inre q(5);
    q.insertone(1);
    q.insertone(2);
    q.insertone(3);
    q.insertone(4);
    q.deletstart();
    q.deletend();

    return 0;
}