/*
Example of doubled linked list....
    NULL    1 --> 2 --> 3 --> 4 --> NULL
        <--  <--  <--  <--  <-- 
*/
#include<bits/stdc++.h>
using namespace std;

class node{
    public :
    int data;
    node* next;
    node* prev;
    
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if (head!=NULL)
    {
        head->prev=n;
    }
    
    head = n;
}

void display(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtEnd(node* &head, int val){

    if (head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    
    node* n = new node(val);
    node* temp = head;
    while (temp->next !=NULL)
    {
        temp = temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void deleteAthead(node* &head){
    node* toDelete = head;
    head = head->next;
    head->prev = NULL; 
    delete toDelete;
}

//DELETION
void deletion(node* &head, int del){

    if (del==1)
    {
        deleteAthead(head);
        return;
    }
    

    node* temp = head;
    int count= 1;
    while (temp!=NULL && count != del)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next!=NULL)
    {
        temp->next->prev = temp->prev;
    }
    
    delete temp;
}

int main()
{
    node* head = NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    deletion(head, 5);
    display(head);
    deletion(head,1);
    display(head);
    return 0;
}
