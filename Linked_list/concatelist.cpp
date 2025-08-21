// Write a program to concatenate two doubly linked lists.

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
class linked_list
{
    Node *first;
    Node *last;
    public:
    linked_list()
    {
        first = NULL;
        last = NULL;
    }
    void insertatfront(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (first == NULL)
        {
            first = newnode;
            last = newnode;
        }
        else
        {
            newnode->next = first;
            first->prev = newnode;
            first = newnode;
        }
    }
    void insertatend(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (first == NULL)
        {
            first = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            newnode->prev = last;
            last = newnode;
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
    void concatenate(linked_list l1, linked_list l2)
    {
        Node *temp = l1.first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = l2.first;
        l2.first->prev = temp;

    }
};
int main()
{
    linked_list l1, l2;
    l1.insertatfront(10);
    l1.insertatfront(20);
    l1.insertatfront(30);
    l1.insertatfront(40);
    l1.insertatfront(50);
    cout<<"list 1 "<<endl;
    l1.display();
    l2.insertatfront(60);
    l2.insertatfront(70);
    l2.insertatfront(80);
    l2.insertatfront(90);
    l2.insertatfront(100);
    cout<<"list 2"<<endl;
    l2.display();
    l1.concatenate(l1, l2);
    cout<<"After concatenation "<<endl;
    l1.display();
    return 0;
}