// #include<iostream>
// using namespace std;
// struct Node{
//     int data;
//     Node* next;
//     Node* prev;
// };
// class linked_list{
//     Node* first;
//     Node* last;
//     public:
//     linked_list()
//     {
//         first =NULL;
//         last =NULL;
//     }
//     void insertatfront(int value)
//     {
//         Node* newnode=new Node();
//         newnode->data=value;
//         newnode->next=NULL;
//         newnode->prev=NULL;
//         if(first==NULL)
//         {
//             first=newnode;
//             last=newnode;
//         }
//         else
//         {
//             newnode->next=first;
//             first->prev=newnode;
//             first=newnode;
//         }
//     }
//     void insertatend(int value)
//     {
//         Node* newnode=new Node();
//         newnode->data=value;
//         newnode->next=NULL;
//         if(first==NULL)
//         {
//             first=NULL;
//             last=NULL;
//         }
//         else{
//             last->next=newnode;
//             newnode->prev=last;
//             last=newnode;
//         }

//     }
//     void insertatpisition(int value,int position)

//     {
//         Node* newnode=new Node();
//         newnode->data=value ;
//         newnode->next=NULL;
//         newnode->prev=NULL;
//         if(position==0)
//         {
//             insertatfront(value);
//         }
//         else
//         {
//             Node* temp=first;
//             for(int i=1;i<position-1;i++)
//             {
//                 temp=temp->next;
//             }
//             newnode->next=temp->next;
//             newnode->prev=temp;
//             temp->next=newnode;
//             newnode->next->prev=newnode;
//         }
//            }
//     void display(){
//         Node* temp ;
//         temp=first;

//         while(temp!=NULL)
//         {
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }

// };

// int main()
// {
//     linked_list l;
//     l.insertatfront(10);
//     l.insertatfront(20);
//     l.insertatfront(30);
//     l.insertatend(40);
//     l.insertatend(50);
//     l.insertatpisition(60,2);

//     l.display();
//  return 0;
// }

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convert2Doublyll(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
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

Node *deletehead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node *deletetail(Node *head)
{
    Node *prev = head;
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *last = head;
    while (last->next != nullptr)
    {
        last = last->next;
    }
    Node *newlast = last->back;
    newlast->next = nullptr;
    delete last;
    return head;
}

Node *deleteatK(Node *head, int k)
{
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;
    if (prev == nullptr && front == nullptr)
    {
        delete temp;
        return nullptr;
    }
    else if (prev == NULL)
    {
        return deletehead(head);
    }
    else if (front == nullptr)
    {
        return deletetail(head);
    }

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return head;
}

//  before the element

Node *inserthead(Node *head, int ele)
{
    Node *newHead = new Node(ele, head, nullptr);
    head->back = newHead;
    return newHead;
}

Node *inserttail(Node *head, int ele)
{
    if (head->next == nullptr)
    {
        return inserthead(head, ele);
    }
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;

    Node *newTail = new Node(ele, tail, prev);
    prev->next = newTail;
    tail->back = newTail;
    return head;
}

Node *insertatk(Node *head, int k, int ele)
{
    Node *temp = head;
    int count = 0;
    if (k == 1)
    {
        return inserthead(head, ele);
    }

    while (temp->next != nullptr)
    {
        count++;
        if (count == k)
        {
            Node *prev = temp->back;
            Node *newNode = new Node(ele, temp, prev);
            prev->next = newNode;
            temp->back = newNode;
            return head;
        }
        temp = temp->next;
    }
    if (temp->next == nullptr)
    {
        return inserttail(head, ele);
    }
    return nullptr;
}

Node *reverse_ll(Node *head)
{
    // //  way one ----------------

    // Node *temp = head;
    // stack<int> st;
    // while (temp != nullptr)
    // {
    //     st.push(temp->data);
    //     temp = temp->next;
    // }
    // temp = head;
    // while (temp != nullptr)
    // {
    //     temp->data = st.top();
    //     st.pop();
    //     temp = temp->next;
    // }

    // // second way -----------

    Node *current = head;
    Node *last = nullptr;
    while (current != nullptr)
    {
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    Node* newHead = last->back;

    return newHead;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7,23};
    Node *head = convert2Doublyll(arr);

    // head = deletehead(head);
    // head = deletetail(head);
    // head = deleteatK(head, 5);
    // head = inserthead(head, 10);
    // head = inserttail(head, 20);
    // head = insertatk(head, 4, 10);
    head = reverse_ll(head);

    print(head);

    return 0;
}