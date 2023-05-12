#include<iostream>
using namespace std;

#define INF 9999

void floyd(){
    int n;
    cout<<"Enter the number of vertices : ";
    cin>>n;
    int matrix[n][n];

    for(int i = 0; i < n;i++){
        for(int j = 0;j < n;j++){
            cout<<'Enter the Edge weight between '<<i<<' '<<j<<' :';
            cin>>matrix[i][j];
        }
    }

    for(int i = 0; i<n;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < n;k++){
                if(matrix[j][i] + matrix[i][k] < matrix[j][k]){
                    matrix[j][k] = matrix[j][i] + matrix[i][k];
                }
            }
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    floyd();
    return 0;
}