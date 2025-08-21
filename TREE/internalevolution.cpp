#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
};
class queueimplementation
{

public:
    Node *first;
    Node *last;
    queueimplementation()
    {
        first = NULL;
        last = NULL;
    }
    void enqueue_using_list(int data) // in linked list insert at end
    {
        Node *newnode = new Node();
        newnode->data = data;
        newnode->next = NULL;
        if (first == NULL)
        {
            first = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }
    }
    void dequeue_using_list() // in linked list its delete at front
    {
        if (first == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else if (first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            Node *temp = first;
            temp = temp->next;
            delete first;
            first = temp;
        }
    }
    void display()
    {
        Node *temp = first;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    cout << "Implimantation of Queue using Linked List :" << endl;
    cout << "--------------------------------------------" << endl;
    queueimplementation q;

    // q.enqueue_using_list(10);
    // q.enqueue_using_list(20);
    // q.enqueue_using_list(30);
    // cout << "Elements contains in queue after enqueue is : " << endl;
    // q.display();
    // cout << "After enqueue Queue contains : " << endl;
    // q.dequeue_using_list();
    // q.display();

    cout << "1.Enqueue\n2.Dequeue\n3.Display\n4.Exit" << endl;
    int n;
    do
    {
        cout << "Enter your choice : " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the element to be inserted in queue: " << endl;
            int a;
            cin >> a;
            q.enqueue_using_list(a);
            break;
        case 2:
            cout << "element is deleted " << endl;
            q.dequeue_using_list();
            break;
        case 3:
            cout << "displaying element present in Queue : " << endl;
            q.display();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            break;
        }
    } while (n != 4);
}