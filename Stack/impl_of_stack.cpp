#include <bits/stdc++.h>
using namespace std;
class stackk
{
    int size;
    int top;
    int data;
    int *st;

public:
    stackk(int s)
    {
        size = s;
        top = -1;
        st = new int[size];
    }
    void push(int data)
    {
        if (top >= size -1)
        {
            cout << "its done with stack" << endl;
            return;
        }
        top++;
        st[top] = data;
        cout << "pushed : " << st[top] << endl;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "nothing to pop" << endl;
            return;
        }
        cout << "poped: " << st[top] << endl;
        top--;
    }
    void st_size()
    {
        cout << "size : " << top + 1 << endl;
    }
    void top_ele()
    {
        cout << "top : " << st[top] << endl;
    }
};

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class stack_ll {
    Node* top;
    int size;
public:
    stack_ll() {
        top = nullptr;
        size = 0;   
    }
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
        cout << "pushed : " << data << endl;
    }
    void pop() {
        if (top == nullptr) {
            cout << "nothing to pop" << endl;
            return;
        }
        cout << "poped: " << top->data << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    void st_size() {
        cout << "size : " << size << endl;
    }
    void top_ele() {
        if (top == nullptr) {
            cout << "stack is empty" << endl;
            return;
        }
        cout << "top : " << top->data << endl;
    }
};

int main()
{
    // stackk ss(5);
    stack_ll ss;

    ss.push(2);
    ss.push(4);
    ss.push(5);
    ss.push(1);
    ss.pop();
    ss.top_ele();
    ss.st_size();
    return 0;
}