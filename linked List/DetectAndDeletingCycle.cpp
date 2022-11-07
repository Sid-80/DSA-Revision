// also called as FLOYDS ALGORITHM / HARE AND TORTOISE ALGORITHM
//E.G. Of cycle in linked list
//  1 ->2 -> 3 -> 4 -> 5
//              /       \
//             9<-8<-7<-6
/*
In hare and tortoise method we move hare two times and tortoise one time
if it is cycle then both will meet at specific step and we can predict that it is cycle
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
    
    cout<<endl;
}

void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count==pos)
        {
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast!= NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if (fast==slow)
        {
            return true;
        }
        
    }
    return false;
}

//Deletion of cycle
/*
The point in cycle where both meet, from that point we have to take anyone of them to head
and we have to start it by moving both only by one position only at a time then at certain step
both will meet each other at the position from where cycle starts.
*/
void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    slow->next = NULL;
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
    insertAtEnd(head,7);
    insertAtEnd(head,8);
    insertAtEnd(head,9);
    makeCycle(head,4);
    // Display(head);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    Display(head);
    return 0;
}
