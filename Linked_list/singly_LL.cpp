// #include <iostream>
// using namespace std;
// struct Node
// {
//     int data;
//     Node *next;
// };
// class linked_list
// {
//     Node *first;
//     Node *last;
// public:
//     linked_list()
//     {
//         first = NULL;
//         last = NULL;
//     }
//     void inseratfront(int value)
//     {
//         Node *newnode = new Node();
//         newnode->data = value;
//         newnode->next = NULL;
//         if (first == NULL)
//         {
//             first = newnode;
//             last = newnode;
//         }
//         else
//         {
//             newnode->next = first;
//             first = newnode;
//         }
//     }
//     void insertatend(int value)
//     {
//         Node *newnode = new Node();
//         newnode->data = value;
//         newnode->next = NULL;
//         if (first == NULL)
//         {
//             first = newnode;
//             last = newnode;
//         }
//         else
//         {
//             last->next = newnode;
//             last = newnode;
//         }
//     }
//     void insertatposition(int position, int value)
//     {
//         Node *newnode = new Node();
//         newnode->data = value;
//         newnode->next = NULL;
//         if (position == 0)
//         {
//             // newnode->next = first;
//             // first = newnode;
//             inseratfront(value);
//             if (last == nullptr)
//             {
//                 // last = newnode;
//                 insertatend(value);
//             }
//         }
//         else
//         {
//             Node *temp = first;
//             for (int i = 1; i < position - 1; i++)
//             {
//                 temp = temp->next;
//             }
//             if (temp == nullptr)
//             {
//                 cout << "Position out of bounds" << std::endl;
//                 delete newnode;
//                 return;
//             }
//             newnode->next = temp->next;
//             temp->next = newnode;
//             if (newnode->next == nullptr)
//             {
//                 last = newnode;
//             }
//         }
//     }
//     void deletatfront()
//     {
//         if (first == NULL)
//         {
//             cout << "List is empty" << endl;
//         }
//         else
//         {
//             Node *temp = first;
//             first = first->next;
//             delete temp;
//         }
//     }
//     void deletatend()
//     {
//         if (first == NULL)
//         {
//             cout << "List is empty" << endl;
//         }
//         else if (first == last)
//         { // whrn only one node is there:
//             delete first;
//             first = NULL;
//             last = NULL;
//         }
//         else
//         {
//             Node *temp = first;
//             while (temp->next != last)
//             {
//                 temp = temp->next;
//             }
//             delete last;
//             last = temp;
//             last->next = NULL;
//         }
//     }
//     void deletatposition(int position)
//     {
//         if (first == NULL)
//         {
//             cout << "List is empty" << endl;
//         }
//         else if (position == 0)
//         {
//             deletatfront();
//         }
//         else
//         {
//             Node *temp = first;
//             for (int i = 1; i < position - 1; i++)
//             {
//                 temp = temp->next;
//             }
//             if (temp == nullptr)
//             {
//                 cout << "Position out of bounds" << std::endl;
//                 return;
//             }
//             Node *temp1 = temp->next;
//             temp->next = temp1->next;
//             delete temp1;
//         }
//     }
//     void display()
//     {
//         Node *temp = first;
//         while (temp != NULL)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };
// int main()
// {
//     linked_list l;
//     int n;
//     cout << "1. Insert at front\n2. Insert at end\n3. Insert at position" << endl;
//     cout << "4. Delete at front\n5. Delete at end\n6. Display\n7. Delet at position." << endl;
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
//             l.insertatposition(position, value);
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
//         case 7:
//         {
//             int position;
//             cout << "Enter the position to delete : ";
//             cin >> position;
//             l.deletatposition(position);
//             break;
//         }
//         default:
//         {
//             cout << "Invalid choice" << endl;
//         }
//         }
//     } while (n != 0);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};


Node *convertarr2ll(vector<int> arr)
{
    Node *head = new Node(arr[0], nullptr);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *deletetail(Node *head)
{
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deletek(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *removeGivenNode(Node *head, int ele)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->data == ele)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->data == ele)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deletehead(Node *head)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *inserhead(Node *head, int ele)
{
    Node *temp = new Node(ele, head);
    // Node* temp=new Node(ele,nullptr);
    // temp->next = head;
    // head = temp;
    return temp;
}

Node *insertail(Node *head, int ele)
{
    Node *last = new Node(ele, nullptr);
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = last;
    last->next = nullptr;
    return head;
}

Node *insertatposition(Node *head, int k, int ele)
{
    if (head == nullptr)
    {
        if (k == 1)
        {
            return new Node(ele, nullptr);
        }
        else
            return nullptr;
    }
    if (k == 1)
    {
        Node *temp = new Node(ele, head);
        return temp;
    }
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        if (count == k - 1)
        {
            Node *newnode = new Node(ele, nullptr);
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *reverse_ll(Node *head)
{
    // Node* temp = head;
    // stack<int> st;
    // while(temp != nullptr)
    // {
    //     st.push(temp->data);
    //     temp = temp->next;
    // }
    //  temp = head;
    //  while (temp != nullptr)
    //  {
    //     temp->data = st.top();
    //     st.pop();
    //     temp = temp->next;
    //  }
    //  return head;

    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// int main()
// {
//     // Node* y = new Node(5,nullptr);
//     // cout<< y->data<<endl;
//     vector<int> arr = {2, 4, 5, 6, 7};
//     Node *head = convertarr2ll(arr);
//     // head = deletehead(head);
//     // head = deletetail(head);
//     // head = deletek(head, 1);
//     // head = removeGivenNode(head, 7);
//     // head = inserhead(head, 5);
//     // head = insertail(head, 10);
//     // head = insertatposition(head,2,8);
//     // Node *head1 = reverse_ll(head);
//     // print(head1);

//     return 0;
// }

