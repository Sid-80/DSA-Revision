//  1 -> 2 -> 3 -> 4 -> 5 -> 6
//     if n = 2 then
//  2 -> 1 -> 4 -> 3 -> 6 -> 5

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int a)
    {
        data = a;
        next = NULL;
    }
};

void insertAtEnd(node *&head, int b)
{
    node *n = new node(b);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void Display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *reverseN(node *&head, int N)
{
    node *prevptr = NULL;
    node *currentptr = head;
    node *nextptr;

    int count = 0;
    while (currentptr != NULL && count < N)
    {
        nextptr = currentptr->next;
        currentptr->next = prevptr;
        prevptr = currentptr;
        currentptr = nextptr;

        count++;
    }

    if (nextptr != NULL)
    {
        head->next = reverseN(nextptr, N);
    }

    return prevptr;
}

int main()
{
    node* head = NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    
    Display(head);

    int N=2;
    node* newhead = reverseN(head, N);
    Display(newhead);
    return 0;
}
