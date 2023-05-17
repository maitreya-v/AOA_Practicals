#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    int adj[10][10];
    cout<<"Enter the adjacency matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    int k=1;
    int color[10];
    for(int i=0;i<n;i++){
        color[i]=0;
    } 
    for(int i=0;i<n;i++){
        if(color[i]){
            continue;
        }
        color[i]=k;
        for(int j=0;j<n;j++){
            if(color[j]) continue;
            else if(!color[j] && adj[i][j]==0) {
                color[j]=k;
            }
        }
        k++;
    }
    cout<<k<<"\n";
    return 0;
}