#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

/*********at beginning**************/
void insbeg(Node **head, int x)
{
    Node *n = new Node();
    n->data = x;
    n->next = *head;
    *head = n;
}
/**************at end**************/
void insend(Node **head, int y)
{
    Node *n = new Node();
    Node *last = *head;
    n->data = y;
    n->next = NULL;
    if (*head == NULL)
    {
        *head = n;
        return;
    }
    else
    {
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = n;
    }
}
/**********at point**************/
void inspoint(Node *prev, int x)
{
    if (prev != NULL)
    {
        Node *n = new Node();
        n->data = x;
        n->next = prev->next;
        prev->next = n;
    }
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
    insend(&head, 9);
    insbeg(&head, 2);
    insbeg(&head, 3);
    insbeg(&head, 4);
    insend(&head, 9);
    inspoint(head->next, 22);
    cout << "linked list is ";
    traversal(head);
}