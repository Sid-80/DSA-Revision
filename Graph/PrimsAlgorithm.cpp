#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define V 7

int main(){
	int G[V][V] = {
			   {0,2,0,0,0,10,0},
			   {8,0,6,0,0,0,14},
			   {0,16,0,2,0,0,0},
			   {0,0,12,22,0,18},
			   {0,0,0,22,0,25,4},
			   {10,0,0,0,25,0,0},
			   {0,14,0,1,4,0,0}
			};
	int visit[V];
	int edge=0,cost=0,x,y; 
  	for(int i = 0;i<V;i++){
  		visit[i] = false;
  	}
  	visit[0] = true;
  	while(edge < V-1){
  		int min = INT_MAX;
  		x=0;
  		y=0;
  		for(int i  = 0;i < V;i++){
  			if(visit[i]){
  				for(int j = 0;j < V;j++){
  					if(!visit[j] && G[i][j]){
  						if(min > G[i][j]){
  							min = G[i][j];
  							x=i;
  							y=j;
  						}
  					}
  				}
  			}
  		}
  		cout << x <<  " ---> " << y << " :  " << G[x][y];
	       cout << endl;
	       visit[y] = true;
	       cost+=G[x][y];
	       edge++;
  	}
  	cout<<"Minimum cost : "<<cost<<endl;
  	return 0;
}


