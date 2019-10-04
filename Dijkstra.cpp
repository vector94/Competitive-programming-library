#include <bits/stdc++.h>
using namespace std;
#define fi                      first
#define se                      second
#define mem(array, value)       memset(array, value, sizeof(array))
typedef long long int ll;
typedef pair<int, ll> pii;

const ll INF = 1e18;
const int nax = 1e5 + 5;

vector<pii> adjList[nax];
ll dis[nax];
int pre[nax];
int node;

struct Node
{
    int id;
    ll dist;

    Node() {}

    Node (int id, ll dist){
        this -> id = id;
        this -> dist = dist;
    }

    bool operator < (const Node &a) const {
        return dist > a.dist;
    }
};

priority_queue<Node> PQ;

void dijkstra(int source)
{
    while (!PQ.empty()){
        PQ.pop();
    }
    for (int i = 0; i < nax; i++){
        dis[i] = INF;
        pre[i] = -1;
    }

    Node s(source, 0);
    PQ.push(s);
    dis[source] = 0;

    while (!PQ.empty()){
        Node cur = PQ.top();
        PQ.pop();

        int u = cur.id;
        ll cur_dist = cur.dist;

        if (cur_dist != dis[u]){
            continue;
        }

        for (int i = 0; i < adjList[u].size(); i++){
            int v = adjList[u][i].fi;
            ll cost = adjList[u][i].se;

            if (dis[u] + cost < dis[v]){
                dis[v] = dis[u] + cost;
                Node n(v, dis[v]);
                PQ.push(n);
                pre[v] = u;
            }
        }
    }
}

void reset()
{
    for (int i = 0; i < nax; i++){
        adjList[i].clear();
    }
}

int main()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif

    int edge, source;
    cin >> node >> edge >> source;
    int u, v, weight;
    while (edge--){
        cin >> u >> v >> weight;
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }
    dijkstra(source);

    printf ("Vertex   Distance from Source \n");
    for (int i = 1; i<= node; i++){
        printf ("%d\t\t %d\n", i, dis[i]);
    }

    if (dis[node] == INF){
        cout << "No Path\n";
    }
    else{
        vector<int> path;
        int cur = node;
        while (cur != 1){
            path.push_back(cur);
            cur = pre[cur];
        }
        path.push_back(1);
        for (int i = path.size() - 1; i >= 0; i--){
            cout << path[i] << " ";
        }
        cout << endl;
    }
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
