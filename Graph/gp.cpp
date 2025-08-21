// #include <iostream>
// #include <vector>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node *vertice;
//     Node *edge;
//     Node *next;
//     Node *prev;

//     Node(int data) {
//         this->data = data;
//         this->vertice = NULL;
//         this->edge = NULL;
//         this->next = NULL;
//         this->prev = NULL;
//     }
// };

// class Graph {
// public:
//     Node* head;

//     Graph() {
//         head = NULL;
//     }

//     void addVertice(int data) {
//         Node* newNode = new Node(data);
//         if (head == NULL) {
//             head = newNode;
//         } else {
//             Node* temp = head;
//             while (temp->vertice != NULL) {
//                 temp = temp->vertice;
//             }
//             temp->vertice = newNode;
//         }
//     }

//     void addEdge(int from, int to) {
//         Node* fromNode = findVertice(from);
//         Node* toNode = findVertice(to);
//         if (fromNode == NULL || toNode == NULL) {
//             cout << "One or both vertices not found!" << endl;
//             return;
//         }

//         Node* newEdge = new Node(to);
//         if (fromNode->edge == NULL) {
//             fromNode->edge = newEdge;
//         } else {
//             Node* temp = fromNode->edge;
//             while (temp->next != NULL) {
//                 temp = temp->next;
//             }
//             temp->next = newEdge;
//             newEdge->prev = temp;
//         }
//     }

//     Node* findVertice(int data) {
//         Node* temp = head;
//         while (temp != NULL) {
//             if (temp->data == data) {
//                 return temp;
//             }
//             temp = temp->vertice;
//         }
//         return NULL;
//     }

//     void display() {
//         Node* temp = head;
//         while (temp != NULL) {
//             cout << "Vertice " << temp->data << ": ";
//             Node* edgeTemp = temp->edge;
//             while (edgeTemp != NULL) {
//                 cout << edgeTemp->data << " ";
//                 edgeTemp = edgeTemp->next;
//             }
//             cout << endl;
//             temp = temp->vertice;
//         }
//     }
// };

// int main() {
//     Graph g;
//     g.addVertice(1);
//     g.addVertice(2);
//     g.addVertice(3);
//     g.addVertice(4);
//     g.addEdge(1,3);
//     g.addEdge(1,4);
//     g.addEdge(2,3);
//     g.addEdge(2,4);

//     g.display();

//     return 0;
// }

