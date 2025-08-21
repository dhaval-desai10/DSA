// 

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
    
    
    void deletatfront()
    {
        if (first == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = first;
            first = first->next;
            delete temp;
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
    linked_list l;

    l.inseratfront(3);
    l.inseratfront(4);
    l.inseratfront(5);

    l.deletatfront();

    l.deletatfront();

    l.display();

//     int n;
//     cout << "1. Insert at front\n2. Insert at end\n3. Insert at position" << endl;
//     cout << "4. Delete at front\n5. Delete at end\n6. Display" << endl;
//     cout << "0. exit " << endl;

//     do
//     {
//         cout << "Enter the chooice : ";
//         cin >> n;
//         switch (n)
//         {
//         case 1:
//         {
//             int value;
//             cout << "Enter the value to insert at front : ";
//             cin >> value;
//             l.inseratfront(value);
//             break;
//         }
//         case 2:
//         {
//             int value;
//             cout << "Enter the value to insert at end : ";
//             cin >> value;
//             l.insertatend(value);
//             break;
//         }
//         case 3:
//         {
//             int position, value;
//             cout << "Enter the position and value to insert at position : ";
//             cin >> position >> value;
            
//             break;
//         }
//         case 4:
//         {
//             l.deletatfront();
//             break;
//         }
//         case 5:
//         {
//             l.deletatend();
//             break;
//         }
//         case 6:
//         {
//             l.display();
//             break;
//         }
       
//         default:
//         {
//             cout << "Invalid choice" << endl;
//         }
//         }
//     } while (n != 0);

//     return 0;
}