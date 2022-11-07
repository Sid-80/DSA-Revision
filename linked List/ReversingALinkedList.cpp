//we have to do following type :
//  1 -> 2 -> 3 -> 4 -> NULL
//  NULL <- 1 <- 2 <- 3 <- 4
#include<iostream>
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

void insertAtEnd(node* &head, int b){
    node* n = new node(b);
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

void Display(node* head){
    node* temp = head;
    while (temp != NULL)
    {
        cout<< temp->data <<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* reverse(node* &head){
    node* prevptr = NULL;
    node* currentptr = head;
    node* nextptr ;

    while (currentptr != NULL)
    {
        nextptr = currentptr->next;
        currentptr->next = prevptr;

        prevptr = currentptr;
        currentptr = nextptr;

    }
    
    return prevptr;
}

node* reverseRecursive(node* &head){
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    
    node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next=NULL;
    return newHead;
}

int main()
{
    node* head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    Display(head);

    node* newHead = reverse(head);
    Display(newHead);

    node* newhead = reverseRecursive(newHead);
    Display(newhead);
    return 0;
}
