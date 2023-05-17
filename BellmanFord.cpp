#include<iostream>
using namespace std;


int BellmanFord(int distmat[20][20],int numVertices,int edges[20][2],int numEdges){

        int distances[20],parents[20],source,u,v;


        for(int i=0;i<numVertices;i++){
            distances[i]=1000;
            parents[i]=-1;
        }

        cout<<"Enter the source"<<endl;
        cin>>source;

        for(int i=0;i<numVertices-1;i++){
            for(int j=0;j<numEdges;j++){
                u=edges[j][0];
                v=edges[j][1];

                if(distances[u]+distmat[u][v]<distances[v]){
                    distances[v]=distances[u]+distmat[u][v];
                    parents[v]=u;
                }
            }
        }
        bool hasNegativeCycle=true;
        for(int i=0;i<numEdges;i++){
            u=edges[i][0];
            v=edges[i][1];

            if(distances[u]+distmat[u][v]<distances[v]){
                hasNegativeCycle=false;
            }
        }
        if(!hasNegativeCycle) {
            for(int i=0;i<numVertices;i++){
                cout<<"Vertex "<<i+1<<" distance "<<distances[i]<<" parent "<<parents[i]<<endl;
            }
        }

        return hasNegativeCycle;

}

int main()
{
    int numVertices,numEdges=0,distmat[20][20],edges[20][2];

    cout<<"Enter the number of vertices"<<endl;
    cin>>numVertices;

    cout<<"Enter the variables of the distance matrix"<<endl;
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            cin>>distmat[i][j];

        if(distmat[i][j]!=0){
            edges[numEdges][0]=i;
            edges[numEdges][1]=j;
            numEdges++;
        }   
        }
    }

    int flag=BellmanFord(distmat,numVertices,edges,numEdges);
    if(flag){
        cout<<"Negative cycle exists"<<endl;
    }
    return 0;
}