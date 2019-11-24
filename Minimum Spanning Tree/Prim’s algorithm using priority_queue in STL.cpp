#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define INF 1e9

int node;
vector<pii> graph[20009];

void primMST(int src)
{
    priority_queue<pii, vector<pii>, greater<pii> > PQ;
    vector<int> key(node, INF);
    vector<int> parent(node, -1);
    vector<bool> inMST(node, false);

    PQ.push(make_pair(0, src));
    key[src] = 0;

    while (!PQ.empty()){
        int u = PQ.top().second;
        PQ.pop();

        inMST[u] = true;

        for (int i = 0; i<graph[u].size(); i++){
            int v = graph[u][i].first;
            int weight = graph[u][i].second;
            if (inMST[v] == false && key[v] > weight){
                key[v] = weight;
                PQ.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i<=node; i++){
        printf ("%d - %d\n", parent[i], i);
    }
}

int main ()
{
    int edge;
    cin >> node >> edge;
    int u, v, weight;
    while (edge--){
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight));
    }
    primMST(0);
    return 0;
}
/// Input
/*
5 7
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
1 4 9
*/
