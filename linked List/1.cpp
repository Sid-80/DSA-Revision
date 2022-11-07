//Limitations in array:
//1.Fixed size   2.contigous block of memory    3.inserting/deleting is costly
/*
Linked List --> |Data|Next|  -->next means addresss of next data to be stored

        10k      20k        30k
     |1|20k|   |2|30k|    |3|NULL|

Head pointer --> it stores the address from which the linked list gets started

*/
#include<bits/stdc++.h>
using namespace std;

class node{
    public :
    int data;
    node *next;

    node(int a){
        data = a;
        next = NULL;
    }
};

//inserting a data in linked list
void insertAtEnd(node* &head, int b){
    node* n = new node(b);
    //n is apointer where it locates the position of stored element b
    //head stores the value
    if (head == NULL)
    {
        head = n;
        return;
    }
    
    node* temp = head;
    while(temp -> next != NULL){
        temp=temp->next;
    }
    temp->next=n;
}

//displaying linked list
void Display(node* head){
    node* temp = head;
    while (temp != NULL)
    {
        cout<< temp->data <<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//inserting at head
void insertAtHead(node* &head, int b){
    node* n = new node(b);
    n->next = head;
    head = n;
}

//deletion of head
void deleteAtHead(node* &head){

    if (head==NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    
    node* todelete = head;
    head=head->next;
    delete todelete;
}

//deletion of member from linked list
void deletion(node* &head, int a){
    node* temp=head;
    while(temp->next->data != a){ //jab tak temp ka next ka data
        temp=temp->next;
    }
    node* toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}

int main()
{
    node* head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    Display(head);
    insertAtHead(head,0);
    Display(head);
    deletion(head,3);
    Display(head);
    deleteAtHead(head);
    Display(head);

    return 0;
}
