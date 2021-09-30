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

const int nax = 1e4 + 5;
int level[nax], parent[nax][20];
int cost[nax];
vector<pii> graph[nax];
int n;

void dfs(int u, int p)
{
    level[u] = 1 + level[p];
    parent[u][0] = p;
    for (auto x : graph[u]){
        int v = x.fi;
        int w = x.se;
        if (v == p){
            continue;
        }
        cost[v] = cost[u] + w;
        dfs(v, u);
    }
}

void pre_cal()
{
    for (int i = 1; (1 << i) <= n; i++){
        for (int j = 1; j <= n; j++){
            if (parent[j][i - 1] != -1){
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
            }
        }
    }
}

int LCA(int u, int v)
{
    if (level[u] < level[v]){
        swap(u, v);
    }
    int d = level[u] - level[v];
    for (int i = 15; i >= 0; i--){
        if ((1 << i) & d){
            u = parent[u][i];
        }
    }
    if (u == v){
        return u;
    }
    for (int i = 15; i >= 0; i--){
        if (parent[u][i] != -1 && parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int get_distance(int u, int v)
{
    int w = LCA(u, v);
    return (cost[u] + cost[v] - 2 * cost[w]);
}

int kth_node(int u, int v, int k)
{
    int w = LCA(u, v);
    int d = level[u] - level[w];
    if (k <= d + 1){
        k--;
        for (int i = 15; i >= 0; i--){
            if ((1 << i) & k){
                u = parent[u][i];
            }
        }
        return u;
    }
    else{
        k -= (d + 1);
        d = level[v] - level[w];
        d -= k;
        for (int i = 15; i >= 0; i--){
            if ((1 << i) & d){
                v = parent[v][i];
            }
        }
        return v;
    }
}

void Clear()
{
    for (int i = 1; i <= n; i++){
        graph[i].clear();
    }
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n - 1; i++){
            int u, v, c;
            cin >> u >> v >> c;
            graph[u].pb(mp(v, c));
            graph[v].pb(mp(u, c));
        }
        level[0] = -1;
        mem(parent, -1);
        dfs(1, 0);
        pre_cal();
        string type;
        while (cin >> type){
            if (type == "DONE"){
                break;
            }
            if (type == "DIST"){
                int u, v;
                cin >> u >> v;
                int res = get_distance(u, v);
                cout << res << endl;
            }
            else{
                int u, v, k;
                cin >> u >> v >> k;
                int res = kth_node(u, v, k);
                cout << res << endl;
            }
        }
        cout << endl;
        Clear();
    }
    return 0;
}

