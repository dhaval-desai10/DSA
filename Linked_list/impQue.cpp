#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
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
    void inseratfront(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        newnode->next = NULL;
        if (first == NULL)
        {
            first = newnode;
            last = newnode;
        }
        else
        {
            newnode->next = first;
            first = newnode;
        }
    }
     void deletatend()
    {
        if (first == NULL)
        {
            cout << "List is empty" << endl;
        }
        else if (first == last)
        { // whrn only one node is there:
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            Node *temp = first;
            while (temp->next != last)
            {
                temp = temp->next;
            }
            delete last;
            last = temp;
            last->next = NULL;
        }
    }
};
int main()
{
    

}