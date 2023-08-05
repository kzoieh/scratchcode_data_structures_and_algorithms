#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }

};

// class Node
// {
//     public:
//     int data;
//     Node *next;

//     Node(int value)
//     {
//         data = value;
//         next = NULL;
//     }

// };

//An explicitly defined functon to print values of Linked List
void printList(Node* node)
{
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    return;
}

//An explicitly defined functon to add Node in front of Linked List

Node *addNode_atFront(Node *head, int value)
{
    Node * newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    return head;
}

//An explicitly defined functon to add Node in middle of Linked List

void addNode_inMiddle(Node *node, int key, int value)
{
    while(node->data != key)
    {
        node = node->next;
    }
    
    Node *temp = node->next;
    Node *newNode = new Node(value);
    node->next = newNode;
    newNode->next = temp;
}

//An explicitly defined functon to add Node at last of Linked List

void addNode_atLast(Node *node, int value)
{
    while(node->data != NULL)
    {
        node = node->next;
    }

    Node *newNode = new Node(value);
    node->next = newNode;
    newNode->next = NULL;    
}

int main()
{
    //Declaring a pointer pointing to Node type memory space
    Node *head;                                  //int *ptr;

    //Dynamic memory allocaton and data intialisation
    head = new Node(2);
    printList(head);
    cout<<endl;

    head = addNode_atFront(head, 0);
    printList(head);
    cout<<endl;

    addNode_inMiddle(head, 0, 1);
    printList(head);
    cout<<endl;

    addNode_atLast(head, 3);
    printList(head);
    cout<<endl;
}