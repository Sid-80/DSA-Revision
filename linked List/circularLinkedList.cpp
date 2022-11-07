#include<iostream>
using namespace std;

class node{
    public :
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }

};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if (head == NULL)
    {
        n->next=n;
        head = n;
        return;
    }
    

    node* temp = head;

    while (temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtEnd(node* &head, int val){

    if (head==NULL)
    {
        insertAtHead(head, val);
        return;
    }
    
    node* n = new node(val);
    node* temp = head;

    while (temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deleteAtHead(node* &head){
    node* temp = head;
    while (temp->next!=head)
    {
        temp = temp->next;
    }
    node* toDelete = head;
    temp->next = head->next;
    head = head->next;
    delete toDelete;
}

void deletion(node* &head, int posit){

    if (posit==1)
    {
        deleteAtHead(head);
    }
    
    node* temp = head;
    int count = 1;
    while (count!=posit-1)
    {
        temp = temp->next;
        count++;
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void display(node* head){
    node* temp = head;
    do
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    } while (temp!=head);
    cout<<endl;
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
    deletion(head,1);
    display(head);
    return 0;
}
