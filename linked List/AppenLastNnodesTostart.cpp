#include<iostream>
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

int length(node* head){
    int l=0;
    node* temp = head;
    while (temp!=NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node* AppendN(node* &head, int N){
    node* newHead;
    node* newEnd;
    node* End = head;

    int l = length(head);
    int count = 1;

    while (End->next!=NULL)
    {
        if (count==l-N)
        {
            newEnd = End;
        }
        if (count==l-N+1)
        {
            newHead=End;
        }
        End = End->next;
        count++;
    }
    newEnd->next = NULL;
    End->next=head;
    return newHead;
}

int main()
{
    node* head = NULL;
    int arr[]={1,2,3,4,5,6};
    for (int i = 0; i < 6; i++)
    {
        insertAtEnd(head,arr[i]);
    }
    Display(head);
    node* newHead = AppendN(head,3);
    Display(newHead);
    
    return 0;
}
