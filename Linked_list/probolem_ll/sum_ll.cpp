
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

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *list1(vector<int> arr1)
{
    if (arr1.empty())
        return nullptr;
    Node *head = new Node(arr1[0], nullptr);
    Node *curr = head;
    for (int i = 1; i < arr1.size(); ++i)
    {
        curr->next = new Node(arr1[i], nullptr);
        curr = curr->next;
    }
    return head;
}
Node *list2(vector<int> arr2)
{
    if (arr2.empty())
        return nullptr;
    Node *head = new Node(arr2[0], nullptr);
    Node *curr = head;
    for (int i = 1; i < arr2.size(); ++i)
    {
        curr->next = new Node(arr2[i], nullptr);
        curr = curr->next;
    }
    return head;
}

Node *print(Node *head)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}

Node *addtwonumber(Node *head1, Node *head2)
{
    Node *dummyNode = new Node(-1);
    Node *curr = dummyNode;
    Node *temp1 = head1;
    Node *temp2 = head2;
    int carry = 0;
    while (temp1 != 0 || temp2 != 0)
    {
        int sum = carry;
        if (temp1)
            sum += temp1->data;
        if (temp2)
            sum += temp2->data;
        Node *newNode = new Node(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;
        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }
    if (carry)
    {
        Node *newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

Node *even_odd_ll(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    // vector<int> arr;
    // Node *temp = head;
    // //  adding odd
    // while (temp != nullptr && temp->next != nullptr)
    // {
    //     arr.push_back(temp->data);
    //     temp = temp->next->next;
    // }
    // if (temp)
    //     arr.push_back(temp->data);

    // // adding even
    // temp = head->next;

    // while (temp != nullptr && temp->next != nullptr)
    // {
    //     arr.push_back(temp->data);
    //     temp = temp->next->next;
    // }
    // if (temp)
    //     arr.push_back(temp->data);

    // // new list

    // int i = 0;
    // temp = head;
    // while (temp != nullptr)
    // {
    //     temp->data = arr[i];
    //     i++;
    //     temp= temp->next;
    // }
    // return head;

    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

Node *sortll_012(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    // int cnt_0 = 0;
    // int cnt_1 = 0;
    // int cnt_2 = 0;
    // Node *temp = head;
    // while (temp != nullptr)
    // {
    //     if (temp->data == 0)
    //         cnt_0++;
    //     else if (temp->data == 1)
    //         cnt_1++;
    //     else
    //         cnt_2++;
    //     temp = temp->next;
    // }
    // temp = head;
    // while (temp != nullptr)
    // {
    //     if (cnt_0 > 0)
    //     {
    //         temp->data = 0;
    //         cnt_0--;

    //     }
    //     else if (cnt_1 > 0)
    //     {
    //         temp->data = 1;
    //         cnt_1--;
    //     }
    //     else
    //     {
    //         temp->data = 2;
    //         cnt_2--;
    //     }
    //     temp = temp->next;
    // }
    // return head;

    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
            temp = temp->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
            temp = temp->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
            temp = temp->next;
        }
    }

    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = (twoHead->next) ? twoHead->next : nullptr;

    zero->next = oneHead->next;
    one->next = twoHead->next;
    two->next = nullptr;

    return zeroHead->next;
}

Node *delete_k_ele_last(Node *head, int k)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    if (cnt == k)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    int stop_Node = cnt - k;
    temp = head;
    while (temp != nullptr)
    {
        stop_Node--;
        if (stop_Node == 0)
        {
            break;
        }
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    return head;
}


int main()
{
    vector<int> arr1 = {1, 1, 0, 0, 2, 2, 2};
    vector<int> arr2 = {6, 9, 8, 2, 1};
    Node *head1 = list1(arr1);
    Node *head2 = list2(arr2);
    // print(head1);
    // print(head2);

    // cout << "sum of this two list " << endl;
    // Node *head = addtwonumber(head1, head2);
    // print(head);
    // cout << "even and odd list " << endl;
    // Node *head = even_odd_ll(head1);
    // print(head);

    // Node *head = sortll_012(head1);
    // print(head);

    Node *head = delete_k_ele_last(head2, 3);
    print(head);

    return 0;
}