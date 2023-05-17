#include <iostream>
using namespace std;
#define INT_MAX 9999
const int MAX_VERTICES = 20;

void BellmanFord(int distmat[MAX_VERTICES][MAX_VERTICES], int numVertices, int edges[MAX_VERTICES][2], int numEdges) {
    int distances[MAX_VERTICES], parents[MAX_VERTICES], source, u, v;

    for (int i = 0; i < numVertices; i++) {
        distances[i] = INT_MAX;
        parents[i] = -1;
    }

    cout << "Enter the source: ";
    cin >> source;

    distances[source] = 0;

    for (int i = 0; i < numVertices - 1; i++) {
        for (int j = 0; j < numEdges; j++) {
            u = edges[j][0];
            v = edges[j][1];

            if (distances[u] != INT_MAX && distances[u] + distmat[u][v] < distances[v]) {
                distances[v] = distances[u] + distmat[u][v];
                parents[v] = u;
            }
        }
    }

    bool hasNegativeCycle = false;

    for (int i = 0; i < numEdges; i++) {
        u = edges[i][0];
        v = edges[i][1];

        if (distances[u] != INT_MAX && distances[u] + distmat[u][v] < distances[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Negative cycle exists" << endl;
    } else {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << " distance " << distances[i] << " parent " << parents[i] << endl;
        }
    }
}

int main() {
    int numVertices, numEdges = 0, distmat[MAX_VERTICES][MAX_VERTICES], edges[MAX_VERTICES][2];

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the values of the distance matrix: " << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> distmat[i][j];

            if (distmat[i][j] != 0) {
                edges[numEdges][0] = i;
                edges[numEdges][1] = j;
                numEdges++;
            }
        }
    }

    BellmanFord(distmat, numVertices, edges, numEdges);

    return 0;
}
