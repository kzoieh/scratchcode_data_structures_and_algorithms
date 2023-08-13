#include<iostream>
using namespace std;
//-----------------------------------------------------------------------------//

//LINKED LIST STRUCTURE

struct Node
{
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        data = value;
        next = NULL;
    }

    Node(int value, Node *nextNode)
    {
        data = value;
        next = nextNode;
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


//-----------------------------------------------------------------------------//


//Explicitly defined functons to print values of Linked List//


//Iterative
void printList(Node* node)
{
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    return;
}


//Recursive
void printListRecursive(Node* node)
{
    if(node == NULL) return;
    cout<<node->data;
    printListRecursive(node->next);
}


//-----------------------------------------------------------------------------//


//An explicitly defined functons to add Node in Linked List//


//In Front of Linked List
Node *addNode_atFront(Node *head, int value)
{
    Node * newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    return head;
}


//In Middle of Linked List
void addNode_inMiddle(Node *node, int key, int value)
{
    while(node->data != key)
    {
        node = node->next;
    }

    Node *newNode = new Node(value);
    newNode->next = node->next;
    node->next = newNode;
}


//At End of Linked List
void addNode_atLast(Node *node, int value)
{
    while(node->next != NULL)
    {
        node = node->next;
    }

    Node *newNode = new Node(value);
    node->next = newNode;
    newNode->next = NULL;    
}


//-----------------------------------------------------------------------------//


//An explicitly defined functon to delete Node in Linked List//

//by value
Node *deleteNode_byValue(Node *head, int val)
{
    if(head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;

    while(temp->data != val)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;
    return head;
}

//by node
void deleteNode_byNode(Node *node)
{
    Node* temp = node;
    temp = temp->next;
    node->data = node->next->data;
    node->next = node->next->next;
    delete temp;
}


//-----------------------------------------------------------------------------//



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

    addNode_atLast(head, 4);
    printList(head);
    cout<<endl;

    addNode_atLast(head, 4);
    printList(head);
    cout<<endl;

    addNode_atLast(head, 5);
    printList(head);
    cout<<endl;

    addNode_atLast(head, 6);
    printList(head);
    cout<<endl;


    head = deleteNode_byValue(head, 4);
    head = deleteNode_byValue(head, 0);
    head = deleteNode_byValue(head, 6);
    printList(head);
    cout<<endl;

    deleteNode_byNode(head->next->next);
    deleteNode_byNode(head);
    printList(head);
    //cout<<endl;

}
