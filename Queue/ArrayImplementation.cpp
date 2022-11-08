// Queue -> Stores a list of items in which an item can be inserted at one end 
//          amd removed from the other end only
//
//   | z | y | 
//    /    \
// front  back

//it follows FIFO = First In First Out

// operations in queue ->
//1.enqueue(x) = inserts an element in queue
//2.dequeue()= removes the front elemnt
//3.peek() = displays the front value
//4.empty()= displays empty or not

#include<bits/stdc++.h>
using namespace std;

#define n 20

class Queue{
    int* arr;
    int front;
    int back;

    public :
    Queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int x){
        if (back==n-1)
        {
            cout<<"Queue is FULL"<<endl;
            return;
        }
        back++;
        arr[back]=x;
        if (front==-1)
        {
            front++;
        }
    }
    void pop(){
        if (front==-1 || front>back)
        {
            cout<<"No elemnts in queue"<<endl;
            return;
        }
        front++;
    }
    int peek(){
        if (front==-1 || front>back)
        {
            cout<<"No elemnts in queue"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        if (front==-1 || front>back)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<"This will be poped : "<<q.peek()<<endl;
    q.pop();
    cout<<"This will be poped : "<<q.peek()<<endl;
    q.pop();
    cout<<"This will be poped : "<<q.peek()<<endl;
    q.pop();
    cout<<"This will be poped : "<<q.peek()<<endl;
    q.pop();
    cout<<"empty : "<<q.empty()<<endl;

    return 0;
}
