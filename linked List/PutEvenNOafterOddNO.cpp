/*
   odd  even
    \    |
    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    |    \
  head evenStart
*/

#include<bits/stdc++.h>
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

void evenAfterOdd(node* &head){
    node* odd =head;
    node* even = head->next;
    node* evenStart = even;
    while (odd->next!=NULL && even->next!=NULL)
    {
        odd->next =  even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next=evenStart;
    if (odd->next != NULL)
    {
        even->next = NULL;
    }
    
}

int main()
{
    node* head = NULL;
    int arr[] = {1,2,3,4,5,6};
    for (int i = 0; i < 6; i++)
    {
        insertAtEnd(head,arr[i]);
    }
    Display(head);
    evenAfterOdd(head);
    Display(head);


    return 0;
}
