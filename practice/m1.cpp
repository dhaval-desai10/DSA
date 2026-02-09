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
    Node(int data)
    {
        this->data = data;
    }
};

// // array to linked list
Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i], nullptr);
        mover->next = newNode;
        mover = mover->next;
    }
    return head;
}

int searchLL(Node *head, int target)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == target)
        {
            return target;
        }
        temp = temp->next;
    }
    return -1;
}

Node *deleteHead(Node *head)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *deleteTail(Node *head)
{
    if (!head)
    {
        return nullptr;
    }
    if (!head->next)
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deletekth(Node *head, int k)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    if (k > count)
        return head;
    else if (k == count)
    {
        return deleteTail(head);
    }
    else if (k == 1)
    {
        return deleteHead(head);
    }
    for (int i = 1; i < k - 1; i++)
    {
        temp = temp->next;
    }
    Node *del = temp->next;
    temp->next = del->next;
    delete del;
    return head;
}

Node *deleteVal(Node *head, int val)
{
    if (!head)
        return nullptr;
    if (head->data == val)
    {
        Node *del = head;
        head = head->next;
        delete del;
        return head;
    }
    Node *prev = head;
    Node *curr = head->next;
    while (curr)
    {
        if (curr->data == val)
        {
            prev->next = curr->next;
            delete curr;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

Node *inserthead(Node *head, int val)
{
    Node *newnode = new Node(val, nullptr);
    newnode->next = head;
    return newnode;
}

Node *inserttail(Node *head, int val)
{
    Node *newNode = new Node(val, nullptr);
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = nullptr;
    return head;
}

Node *insertatK(Node *head, int k, int val)
{
    if (head == nullptr)
    {
        if (k == 1)
        {
            Node *newNode = new Node(val);
            return newNode;
        }
        return nullptr;
    }
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
        if (k > count + 1)
            return head;
        Node *newNode = new Node(val);
        Node *cur = head;
        for (int i = 1; i < k - 1; i++)
        {
            cur = cur->next;
        }
        Node *forw = cur->next;
        cur->next = newNode;
        newNode->next = forw;
        return head;
    }
}

Node *insertbeforVal(Node *head, int val, int put)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->data == val)
    {

        Node *newNode = new Node(put);
        newNode->next = head;
        return newNode;
    }
    Node *temp = head;
    while (temp)
    {
        Node *prev = temp;
        temp = temp->next;
        if (temp->data == val)
        {
            Node *newNode = new Node(put);
            prev->next = newNode;
            newNode->next = temp;
            return head;
        }
    }
    return head;
}

Node *evenoddLL(Node *head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;
    if (head == nullptr || head->next == nullptr)
        return head;
    while (even && even->next)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

Node *sortLL_0_1_2(Node *head)
{
    Node *temp = head;
    // int count0 = 0, count1 = 0, count2 = 0;
    // while (temp)
    // {
    //     if (temp->data == 0)
    //     {
    //         count0++;
    //     }
    //     else if (temp->data == 1)
    //     {
    //         count1++;
    //     }
    //     else
    //         count2++;
    //     temp = temp->next;
    // }
    // temp = head;
    // while (count0)
    // {
    //     count0--;
    //     temp->data = 0;
    //     temp = temp->next;
    // }
    // while (count1)
    // {
    //     count1--;
    //     temp->data = 1;
    //     temp = temp->next;
    // }
    // while (count2)
    // {
    //     count2--;
    //     temp->data = 2;
    //     temp = temp->next;
    // }

    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    while (temp)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    return zeroHead->next;

    // return head;
}

Node *reverseLL(Node *head)
{
    Node *temp = head;
    Node *front;
    Node *prev = nullptr;
    while (temp)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

//  // think thorugh the subproblem from smallest by taking the single node first and make it as head then take the more node two node then three node so three node call subproblem of two node that how recursion is work

Node *reverseLL_recursion(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *newHead = reverseLL_recursion(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return (newHead);
}

Node *add1LL(Node *head)
{
    if (!head)
        return new Node(1);
    Node *temp = head;
    int carry = 1;
    int sum = 0;
    Node *prev;
    while (temp)
    {
        sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;
        prev = temp;
        temp = temp->next;
    }
    if (carry)
    {
        Node *newNode = new Node(carry);
        prev->next = newNode;
        newNode->next = nullptr;
    }
    return head;
}

Node *intersection_of_2LL(Node *head1, Node *head2)
{
    Node* t1 = head1;
        Node* t2 = head2;
        while (t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
            if (t1 == t2) {
                return t1;
            }
            if (t1 == nullptr) {
                t1 = head2;
            }
            if (t2 == nullptr) {
                t2 = head1;
            }
        }
        return t1;

    // map<Node *, int> mp;
    // Node *temp = head1;
    // while (temp)
    // {
    //     mp[temp] = 1;
    //     temp = temp->next;
    // }
    // temp = head2;
    // while (temp)
    // {
    //     if (mp.find(temp) != mp.end())
    //     {
    //         return temp;
    //     }
    //     temp = temp->next;
    // }
    // return nullptr;
}

void print(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        length++;
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "list length : " << length << endl;
}


int main()
{
    vector<int> arr = {9, 9, 9};
    // Node *y = new Node(arr[0], nullptr);
    // cout << y << endl;

    // // 1.
    Node *head = convertArr2LL(arr);
    // // 2.
    // cout << searchLL(head, 8) << endl;

    // // 3.
    // head = deleteHead(head);
    
    // // 4.
    // head = deleteTail(head);

    // // 5.
    // head = deletekth(head, 2);

    // // 6.
    // head = deleteVal(head, 2);

    // // 7.
    // head = inserthead(head, 1);

    // // 8.
    // head = inserttail(head, 10);

    // // 9.
    // head = insertatK(head, 6, 20);

    // // 10.
    // head = insertbeforVal(head, 2, 20);

    // //  11 .
    // head = evenoddLL(head);

    // // 12.
    // vector<int> arr = {2, 2, 0, 1, 2, 1, 1, 0};
    // head = sortLL_0_1_2(head);

    // // 13.
    // head = reverseLL(head);

    // // 14.
    // Node *head = reverseLL_recursion(head);

    // // 15.
    // // Node *head1 = reverseLL_recursion(head);
    // Node *head2 = add1LL(head1);
    // head = reverseLL(head2);

    print(head);

    return 0;
}