#include<bits/stdc++.h>
using namespace std;

#define MAX 20

class Node{
    string city;
    int cost;
    Node* next;
    public:
    friend class cityGraph;
    Node(){
        city = "";
        cost = -1;
        next = NULL;
    }
    Node(string c,int n){
        city= c;
        cost = n;
        next=NULL;
    }
};

class cityGraph{
    Node * headNode[MAX];
    int n;
    string visit[MAX];
    static int cnt;
    public:
    cityGraph(int n1){
        n = n1;
        for (int i = 0; i < n; i++)
        {
            headNode[i] = NULL;
        }
    }
    int getIndex(string);
    void setHeadNodes();
    int visited(string);
    void insert(string,string,int);
    void BFS(string);
    void display();
};

class Que{
    string queue[MAX];
    int f,r;
    public:
    friend class cityGraph;
    Que(){
        f = -1;
        r = -1;
    }
    int QueFull(){
        if(r == MAX-1){
            return 1;
        }
        return 0;
    }
    int QueEmpty(){
        if(f==-1 && r==-1)
            return 1;
        return 0;
    }
    void add(string s){
        if (f==-1)
        {
            f++;
            r++;
            queue[r] = s;
        }else{
            r++;
            queue[r] = s;
        }
    }
    int search(string city){
        if(f==-1 && r==-1){
            return 0;
        }else{
            for(int i = f; i <= r;i++){
                if (queue[i] == city)
                {
                    return 1;
                }
            }
            return 0;
        }
    }
    string del(){
        string city;
        if(QueEmpty()){
            return "Queue is empty !!";
        }else{
            if(f==r){
                city = queue[f];
                f = r = -1;
            }else{
                city = queue[f];
                f++;
            }
            return city;
        }
    }
};

int cityGraph::cnt = 0;

int cityGraph::visited(string s1){
    for (int i = 0; i < cnt; i++)
    {
        if(visit[i] == s1)
            return 1;
    }
    return 0;
}

void cityGraph :: BFS(string src){
    string str;
    Que q1;
    Node * start;
    q1.add(src);
    while(q1.QueEmpty() == 0){
        str = q1.del();
        visit[cnt] = str;
        cnt++;
        int ind = getIndex(str);
        start = headNode[ind];
        while (start->next != NULL)
        {
            start = start->next;
            if(!q1.search(start->city) && !visited(start->city))
                q1.add(start->city); 
        }
        
    }
}

void cityGraph :: display(){
    Node * temp;
    for(int i = 0;i < n;i++){
        temp = headNode[i];
        while(temp != NULL){
            cout<<temp->city<<" --> ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int cityGraph :: getIndex(string c1){
    for(int i = 0;i < n;i++){
        if(headNode[i]->city == c1){
            return i;
        }
    }
    return -1;
}

void cityGraph::setHeadNodes(){
    string city1,city2,temp;
    int cost;
    int noOfFlights;
    cout<<"****Enter Flight Details****"<<endl;
    cout<<"City Details"<<endl;
    for(int i = 0;i < n;i++){
        headNode[i] = new Node;
        cout<<"Enter the name of city : ";
        cin>>headNode[i]->city;
    }
    cout<<"Enter the number of flights : ";
    cin>>noOfFlights;
    for(int i = 0;i < noOfFlights;i++){
        cout<<"Enter source : ";cin>>city1;
        cout<<"Enter destination : ";cin>>city2;
        cout<<"Enter cost : ";cin>>cost;
        insert(city1,city2,cost);
    }
}

void cityGraph :: insert(string c1,string c2, int c){
    Node * source;
    Node * dest = new Node(c2,c);
    int ind = getIndex(c1);
    source = headNode[ind];
    while(source->next != NULL)
        source = source->next;
    source->next = dest;
}



int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of cities : ";cin>>n;
    cityGraph c(n);
    c.setHeadNodes();
    c.display();
    return 0;
}