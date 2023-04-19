#include<iostream>
using namespace std;

#define SIZE 20
#define TRUE 1
#define FALSE 0

int st[10];
int top;

class GraphDFS{
    int v1,v2;
    int visited[SIZE],g[SIZE][SIZE];

    public:
    int n;
    GraphDFS();
    void create();
    void display();
    void DFSrecursive(int);
    friend void push(int);
    friend int pop();
    void DFSnon(int);
};

void push(int item){
    st[++top] = item;
}

int pop(){
    int i;
    i = st[top];
    top--;
    return i;
}

void GraphDFS :: DFSnon(int v1){
    int v2;
    push(v1);
    while (top!=-1)
    {
        v1 = pop();
        if (visited[v1] == FALSE)
        {
            cout<<endl<<v1;
            visited[v1] = TRUE;
        }
        for ( v2 = 0; v2 < n+1; v2++)
        {
            if (g[v1][v2]==TRUE && visited[v2]==FALSE)
            {
                push(v2);
            }
            
        }
        
        
    }
    
}

GraphDFS :: GraphDFS(){
    for ( v1 = 0; v1 < SIZE; v1++)
    {
        for ( v2 = 0; v2 < SIZE; v2++)
        {
            g[v1][v2] = FALSE;
        }
        
    }
    for ( v1 = 0; v1 < SIZE; v1++)
    {
        visited[v1] = FALSE;
    }
}

void GraphDFS :: display(){
    for ( v1 = 0; v1 < n+1; v1++)
    {
        for ( v2 = 0; v2 < n+1; v2++)
        {
            cout<<" "<<g[v1][v2];
        }
        cout<<endl;
    }
    
}

void GraphDFS :: create(){
    int flag;
    char ch;
    n = 0;
    flag = TRUE;
    cout<<"Enter U if graph is undirected or D if directed"<<endl;
    cin>>ch;

    if(ch == 'D')
        flag = FALSE;
    
    do{
        cout<<"Enter the edge of graph or to terminate enter -99"<<endl;
        cin>>v1>>v2;
        if(v1 == -99)
            break;
        
        if(v1 >= SIZE || v2 >= SIZE){
            cout<<"Invalid vertex"<<endl;
            break;
        }else{
            g[v1][v2] = TRUE;
            if(flag){
                g[v2][v1] = TRUE;
            }
            if(v1 > n && v1 > v2){
                n = v1;
            }else if(v2 > n && v2 > v1){
                n = v2;
            }
        }
    }while(1);
}

void GraphDFS :: DFSrecursive(int v1){
    int v2;
    cout<<endl<<v1;
    visited[v1] = TRUE;
    for ( v2 = 0; v2 < n+1; v2++)
    {
        if (g[v1][v2] == TRUE && visited[v2]==FALSE)
        {
            DFSrecursive(v2);
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    GraphDFS g1;
    int v1;
    g1.create();
    cout<<"Adjacency Matrix : \n";
    g1.display();
    int ans;
    cout<<"Enter 1 for recursive traverse and 0 for non : ";
    cin>>ans;
    cout<<"Enter the vertex from which you have to traverse : ";
    cin>>v1;
    ans ? g1.DFSrecursive(v1) : g1.DFSnon(v1);

    return 0;
}
