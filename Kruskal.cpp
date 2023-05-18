#include<iostream>
using namespace std;
int parent[10];
int find(int i){
    while(parent[i])
    i=parent[i];
    return i;
}


int uni(int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}

int main()
{
    int cost[10][10],min=999,mincost=0;
    int n;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    cout<<"Enter the elements of the cost matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }

    int ne=0;
    int a,b,u,v;
    while(ne<n-1){
        min=999;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];

                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v)){
                cout<<"Vertex "<<ne++<<" Edges "<<a<<"-"<<b<<"\n";
                cout<<"Min "<<min<<"\n";
                mincost+=min;
        }   
        cost[a][b]=cost[b][a]=999;
    }
    printf("Minimum cost %d\n",mincost);

    return 0;
}