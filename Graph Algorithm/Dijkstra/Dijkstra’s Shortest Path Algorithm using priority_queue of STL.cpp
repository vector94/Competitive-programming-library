#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

int node;
vector< pair<int, int> >adjList[20009];

void shortestPath (int source)
{
    priority_queue <iPair, vector <iPair>, greater <iPair> > PQ;
    vector<int> distance(node, INT_MAX);
    PQ.push(make_pair(0, source));
    distance[source] = 0;

    while (!PQ.empty()){
        int u =  PQ.top().second;
        PQ.pop();

        for (int i = 0; i<adjList[u].size(); i++){
            int v = adjList[u][i].first;
            int weight = adjList[u][i].second;

            if (distance[v] > distance[u] + weight){
                distance[v] = distance[u] + weight;
                PQ.push(make_pair(distance[v], v));
            }
        }
    }
    printf ("Vertex   Distance from Source \n");
    for (int i = 0; i<node; i++){
        printf ("%d\t\t %d\n", i, distance[i]);
    }
}

int main ()
{
    int edge, source;
    cin >> node >> edge >> source;
    int u, v, weight;
    while (edge--){
        cin >> u >> v >> weight;
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }
    shortestPath(source);
    return 0;
}
/// INPUT
/*
9 14 0
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/

/// output
/*
Vertex   Distance from Source
    0                0
    1                4
    2                12
    3                19
    4                21
    5                11
    6                9
    7                8
    8                14
*/
