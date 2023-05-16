#include<iostream>
using namespace std;

int main()
{
    int n;
    int g[10][10],color[10];
    cout<<"Number of vertices\n";
    cin>>n;
    cout<<"Enter the adjacency matrix";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cin>>g[i][j];
        }
    }

    for(int i=0;i<n;i++){
        color[i]=0;
    }

    int k=1;

    for(int i=0;i<n;i++){
        if(color[i]) continue;

        color[i]=k;

        for(int j=0;j<n;j++){
            if(color[j]) continue;

            if(g[i][j]==0){
                color[j]=k;
            }
              }
        k++;
    }


    printf("Total %d Colors are used\n", k - 1);

    // Print the vertex-color mapping
    printf("Vertex Color\n");
    for (int i = 0; i < n; i++)
        printf("%d %d\n", i + 1, color[i]);
    return 0;
}