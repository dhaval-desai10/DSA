//  diameter of tree 
// 1. Diameter of a tree is the number of nodes on the longest path between two leaves in the tree.
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter the data to insert at left of " << data << ": " << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data to insert at right of " << data << ": " << endl;
    root->right = buildTree(root->right);

    return root;
}
void levelorder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return max(leftHeight, rightHeight) + 1;
}

int diameter(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    int ld=diameter(root->left);
    int rd=diameter(root->right);
    return max(lh+rh+1,max(ld,rd));
}



// Optimized approach


// pair<int,int> fastdiameter(Node* root){
//     if(root==NULL)
//     {
//         return {0,0};
//     }
//     pair<int,int> left=fastdiameter(root->left);
//     pair<int,int> right=fastdiameter(root->right);
//     int height=max(left.first,right.first)+1;
//     int diameter=max(left.first+right.first,max(left.second,right.second));
//     return {height,diameter};
// }
// int diameter(Node* root)
// {
//     return fastdiameter(root).second;
// }





int main() {
    Node* root = NULL;
    root = buildTree(root);
   
    //  1 3 7 -1 -1 11 -1 5 17 -1 -1 -1
    // Add code to traverse and print the tree if needed
    cout << "Level order traversal: " << endl;
    levelorder(root);   
    cout<<endl;
    // cout<<"Height of tree is : "<<fastdiameter(root).first<<endl;
    cout<<"Diameter of tree is : "<<diameter(root)<<endl;

    return 0;
}