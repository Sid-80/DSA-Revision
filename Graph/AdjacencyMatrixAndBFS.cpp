#include<iostream>
using namespace std;

#define SIZE 20
#define TRUE 1
#define FALSE 0

class GraphBFS{
    int v1,v2,g[SIZE][SIZE];
    int front,rear;
    int visit[SIZE],Q[SIZE];
    public:
    int n;
    GraphBFS();
    void display();
    void create();
    void BFS(int v1);
};

GraphBFS :: GraphBFS(){
    for (v1 = 0; v1 < SIZE; v1++)
    {
        for (v2 = 0; v2 < SIZE; v2++)
        {
            g[v1][v2] = FALSE;
        }
    }
    for ( v1 = 0; v1 < SIZE; v1++)
    {
        visit[v1] = FALSE;  
    }
}

void GraphBFS :: display(){
    for ( v1 = 0; v1 < n; v1++)
    {
        for ( v2 = 0; v2 < n; v2++)
        {
            cout<<" "<<g[v1][v2];
        }
        cout<<endl;
    }
    
}

void GraphBFS :: create(){
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

void GraphBFS ::BFS(int v1){
    int v2;
    visit[v1] = TRUE;
    front=rear = -1;
    Q[++rear] = v1;
    while (front != rear)
    {
        v1 = Q[++front];
        cout<<endl<<v1;
        for(v2 = 0;v2 < n;v2++){
            if (g[v1][v2]==TRUE && visit[v2]==FALSE)
            {
                Q[++rear] = v2;
                visit[v2] = TRUE;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int v1;
    GraphBFS g1;
    g1.create();
    g1.display();
    cout<<"Enter the vertex through u have to traverse : ";
    cin>>v1;
    if (v1>=SIZE)
    {
        cout<<"Invalid Vertex !!"<<endl;
    }
    cout<<"\t Breath First Search \n";
    g1.BFS(v1);

    return 0;
}
