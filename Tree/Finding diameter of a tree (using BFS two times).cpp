/// Reference: https://www.quora.com/How-do-I-find-the-diameter-of-a-tree
/// We choose an arbitrary node (x) and find the farthest node from (x), let it be (y) (first bfs)
/// then we do another traversal to find the farthest node from (y) , let it be (z).     (second bfs)
/// Then diameter is the distance between (y) and (z).

#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii     	            pair<int,int>
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define fastRead 	            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#ifdef Lollipop
    #define line                    cout << "\n===================\n"
    #define trace(...)              __f( #__VA_ARGS__ , __VA_ARGS__ )
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " = " << arg1 << "\n";
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " = " << arg1 << " , ";
    __f(comma + 1, args...);
    }
#else
    #define line
    #define trace(...)
#endif

const int nax = 1e5 + 5;
vector<int> graph[nax];     /// Graph
int dist[nax];              /// Distance array (number of nodes in the path from root)
int n;                      /// Number of nodes
queue<int> Q;

pii bfs(int root){
    mem(dist, 0);
    while (!Q.empty()){
        Q.pop();
    }
    dist[root] = 1;
    Q.push(root);
    while (!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for (auto next : graph[cur]){
            if (dist[next] != 0){
                continue;
            }
            dist[next] = dist[cur] + 1;
            Q.push(next);
        }
    }
    int mx = 0, mx_vertex = - 1;
    for (int i = 1; i <= n; i++){
        if (dist[i] > mx){
            mx = dist[i];
            mx_vertex = i;
        }
    }
    return pii(mx, mx_vertex);      /// return the number of nodes in the max path and the farthest node
}

int Find_Diameter(int root)
{
    pii p1, p2;
    p1 = bfs(root);         /// bfs from root, p1.second is the farthest node from root
    p2 = bfs(p1.second);    /// bfs from p1.second, p2.first is the diameter of the tree
    return p2.first;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    cout << Find_Diameter(1) << endl;
    return 0;
}
