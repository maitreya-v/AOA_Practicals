#include <iostream>
using namespace std;

#define MAX 10
#define INFINITY 9999

void Dijkstra(int G[MAX][MAX], int n, int startnode)
{

    int cost[MAX][MAX];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = G[i][j];
            }
        }
    }

    int distance[MAX];
    int pred[MAX];
    int count = 1;
    int visited[MAX];

    for (int i = 0; i < n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    visited[startnode] = 1;
    distance[startnode] = 0;
    int nextnode;
    while (count < n - 1)
    {

        int mindistance = INFINITY;
        for (int i = 0; i < n; i++)
        {

            if (distance[i] < mindistance)
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (cost[nextnode][i] + mindistance < distance[i])
            {
                distance[i] = cost[nextnode][i] + mindistance;
                pred[i] = nextnode;
            }
        }

        count++;
    }
    int j;
    for (int i = 0; i < n; i++)
    {
        if (i != startnode)
        {
            cout << "The distance of " << i << " is " << distance[i] << endl;
            cout << "Path " << i;
            j = i;
            do
            {
                j = pred[j];
                cout << " <- " << j;
            } while (j != startnode);
        }
    }
}

int main()
{
    int n;
    int G[MAX][MAX];
    int startnode;
    cout << "Enter the number of nodes" << endl;
    cin >> n;
    cout << "Enter the adjacency matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> G[i][j];
        }
    }
    cout << "Enter the start node" << endl;
    cin >> startnode;
    Dijkstra(G, n, startnode);
    return 0;
}