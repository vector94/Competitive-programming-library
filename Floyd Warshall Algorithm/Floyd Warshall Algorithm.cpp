#include <bits/stdc++.h>
using namespace std;

const int V = 109;
const int INF = 999999;

int node;
int adjMatrix[V][V];
int dist[V][V];

void floydWarshall()
{
    for (int k = 0; k<node; k++){
        for (int i = 0; i<node; i++){
            for (int j = 0; j<node; j++){
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
void printSolution()
{
    for (int i = 0; i<node; i++){
        for (int j = 0; j<node; j++){
            if (dist[i][j] == INF){
                printf ("%7s", "INF");
            }
            else {
                printf ("%7d", dist[i][j]);
            }
        }
        cout << endl;
    }
}

int main ()
{
    for (int i = 0; i<V; i++){
        for (int j = 0; j<V; j++){
            if (i == j){
                adjMatrix[i][j] = 0;
                dist[i][j] = 0;
            }
            else {
                adjMatrix[i][j] = INF;
                dist[i][j] = INF;
            }
        }
    }
    int m;
    cin >> node >> m;
    int u, v, w;
    while (m--){
        cin >> u >> v >> w;
        adjMatrix[u][v] = w;
        dist[u][v] = w;
    }
    floydWarshall();
    printSolution();
    return 0;
}

/*
4 4
0 1 5
0 3 10
1 2 3
2 3 1
*/
