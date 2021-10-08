#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

/*********insertion beginning**************/
void insbeg(Node **head, int x)
{
    Node *n = new Node();
    n->data = x;
    n->next = *head;
    *head = n;
}
/***********concatenation**************/
void concatenation()
{
    
}

/*********traversal***************/
void traversal(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}
/************************************/
int main()
{
    Node *head = NULL;
    insbeg(&head, 1);
    insbeg(&head, 2);
    insbeg(&head, 3);
    insbeg(&head, 4);
    insbeg(&head, 5);
    cout << "linked list is ";
    traversal(head);
}