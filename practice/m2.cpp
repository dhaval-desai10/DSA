#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data, Node *next, Node *back)
    {
        this->data = data;
        this->next = next;
        this->back = back;
    }
    Node(int data)
    {
        this->data = data;
        next = nullptr;
        back = nullptr;
    }
};

Node *conver2DoublyLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->back = temp;
        temp = temp->next;
    }
    return head;
}

Node *deletehead(Node *head)
{
    if (!head)
        return nullptr;
    Node *newhead = head->next;
    if (newhead)
        newhead->back = nullptr;
    delete head;
    return newhead;
}
Node *deletetail(Node *head)
{
    if (!head)
        return nullptr;
    if (!head->next)
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    Node *prev = temp->back;
    prev->next = nullptr;
    delete temp;
    return head;
}

Node *deletekth(Node *head, int k)
{
    if (!head)
        return nullptr;
    if (k == 1)
        return deletehead(head);
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        if (count == k)
            break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;
    if (prev == nullptr && front == nullptr)
    {
        delete temp;
        return nullptr;
    }
    else if (prev == nullptr)
    {
        return deletehead(head);
    }
    else if (front == nullptr)
    {
        return deletetail(head);
    }
    prev->next = front;
    front->back = prev;
    delete temp;
    return head;
}

void deletenode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;
    if (front == nullptr)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
}

Node *inserthead(Node *head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head->back = newNode;
    newNode->back = nullptr;
    return newNode;
}

Node *inserttail(Node *head, int val)
{
    Node *temp = head;
    Node *prev;
    while (temp->next)
    {
        prev = temp;
        temp = temp->next;
    }
    Node *newNnode = new Node(val);
    prev->next = newNnode;
    newNnode->back = prev;
    newNnode->next = temp;
    temp->back = newNnode;
    return head;
}

Node *insertatk(Node *head, int val, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    int count = 0;
    while (temp)
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
    if (temp->back == nullptr)
    {
        return inserthead(head, val);
    }
    else if (front == nullptr)
    {
        return inserttail(head, val);
    }

    Node *newNode = new Node(val);
    prev->next = newNode;
    newNode->back = prev;
    newNode->next = front;
    front->back = newNode;
    return head;
}

void insertbeforNode(Node *temp, int val)
{
    Node *newNode = new Node(val);
    Node *prev = temp->back;
    Node *front = temp->next;
    prev->next = newNode;
    newNode->back = prev;
    newNode->next = temp;
    temp->back = newNode;
}

Node *reverseList(Node *head)
{
    // Node *temp = head;
    Node *cur = head;
    Node *last = nullptr;
    while (cur != nullptr)
    {
        last = cur->back;
        cur->back = cur->next;
        cur->next = last;
        cur = cur->back;
    }
    return last->back;
}

Node *deleteallNode_key(Node *head, int key)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            Node *nextNode = temp->next;
            Node *prevNode = temp->back;
            if (temp == head)
            {
                head = nextNode;
                if (head)
                    head->back = nullptr;
            }
            else
            {
                if (nextNode)
                    nextNode->back = prevNode;
                if (prevNode)
                    prevNode->next = nextNode;
            }
            delete temp;
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        Node *prev = temp;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 3, 2, 4};
    Node *head = conver2DoublyLL(arr);

    // // 1.
    // head = deletehead(head);

    // // 2.
    // head = deletetail(head);

    // // 3.
    // head = deletekth(head, 3);

    // // 4.
    // deletenode(head->next->next->next);

    // // 5. insert befor head ---all before value;
    // head = inserthead(head, 10);

    // // 6. insert at tail
    // head = inserttail(head, 10);

    // // 7. insert at k
    // head = insertatk(head, 10, 3);

    // // 8.
    // insertbeforNode(head->next->next->next,10);

    // // 9. reverse the list
    // head = reverseList(head);

    // // 10.
    deleteallNode_key(head, 3);

    // print(head);

    



    return 0;
}