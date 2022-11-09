// stack-> Stores a list of items in which an item can be added
//         or removed from the list only at one end.
// It is based on LIFO mechanism -> L  Last
//                                  I  In
//                                  F  First
//                                  O  Out
// Operations on Stack :
// push(x)->Element will get added at the top
// pop() -> Removes top most element
// top() -> Returns the topmost value
// empty() -> It states that the stack is empty or not
#include <bits/stdc++.h>
using namespace std;

#define n 100

class Stack
{
    int *arr;

public:
    int top;
    void stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No elements to pop" << endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "No elements in stack" << endl;
            return -1;
        }

        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.empty()<<endl;
    
    return 0;
}