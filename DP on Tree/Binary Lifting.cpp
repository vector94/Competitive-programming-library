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
int level[nax];
int parent[nax][25];
/// parent[u][i] -> parent of u from 2^i distance above;
vector<int> graph[nax];
int n;

/// simple dfs to calculate the level of each node and immediate parent which is parent[u][o]
void dfs(int u, int p)
{
    level[u] = 1 + level[p];
    parent[u][0] = p;
    for (auto v : graph[u]){
        if (v == p){
            continue;
        }
        dfs(v, u);
    }
}

/// calculating the DP
/**
    let, u = current node
    x = parent[u][i], parent of u at distance 2^i
    y = parent[x][i]
    then parent[u][i + 1] = parent[x][i] = y
**/
void pre_cal()
{
    for (int i = 1; (1 << i) <= n; i++){
        for (int j = 1; j <= n; j++){
            int x = parent[j][i - 1];
            if (x){
                parent[j][i] = parent[x][i - 1];
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
    for (int i = 20; i >= 0; i--){
        if ((1 << i) & d){
            u = parent[u][i];
        }
    }
    if (u == v){
        return u;
    }
    for (int i = 20; i >= 0; i--){
        if (parent[u][i] != 0 && parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main ()
{
    #ifdef Lollipop
        //freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    cin >> n;
    for (int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    level[0] = -1;
    dfs(1, 0);
    pre_cal();
    return 0;
}
