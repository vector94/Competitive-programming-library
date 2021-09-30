#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int node;
vector<pii> graph[20009];
int level[20009];

void shortestPath(int source)
{
    priority_queue<pii, vector<pii>, greater<pii> > PQ;
    memset(level, -1, sizeof(level));
    PQ.push(make_pair(0, source));
    while (!PQ.empty()){
        int current = PQ.top().second;
        int currentWeight = PQ.top().first;
        PQ.pop();
        if (level[current] == -1){
            level[current] = currentWeight;
            for (int i = 0; i<graph[current].size(); i++){
                int adjNode = graph[current][i].first;
                int adjNodeWeight = graph[current][i].second;
                if (level[adjNode] == -1){
                    PQ.push(make_pair(level[current]+adjNodeWeight, adjNode));
                }
            }
        }
    }
    printf ("Vertex   Distance from Source \n");
    for (int i = 0; i<node; i++){
        printf ("%d\t\t %d\n", i, level[i]);
    }
}

int main ()
{
    int edge, source;
    cin >> node >> edge >> source;
    int u, v, weight;
    while (edge--){
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight));
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
