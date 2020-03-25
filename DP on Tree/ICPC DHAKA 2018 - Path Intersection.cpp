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
int level[nax];
int parent[nax][20];
bitset<nax> path[nax];
vector<int> graph[nax];
int n;

void dfs(int u, int p)
{
    level[u] = 1 + level[p];
    parent[u][0] = p;
    for (int v : graph[u]){
        if (v == p){
            continue;
        }
        path[v] |= path[u];
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

bitset<nax> get_path(int u, int v)
{
    int l = LCA(u, v);
    bitset<nax> ret = (path[u] | path[v]) ^ path[l];
    ret[l] = true;
    return ret;
}

void Clear()
{
    for (int i = 1; i <= n; i++){
        graph[i].clear();
        path[i].reset();
        path[i][i] = true;
    }
    level[0] = -1;
    mem(parent, -1);
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    scanf ("%d", &t);
    for (int cs = 1; cs <= t; cs++){
        printf ("Case %d:\n", cs);
        scanf ("%d", &n);
        Clear();
        for (int i = 1; i <= n - 1; i++){
            int u, v;
            scanf ("%d %d", &u, &v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        dfs(1, 0);
        pre_cal();
        int q;
        scanf ("%d", &q);
        while (q--){
            int k;
            scanf ("%d", &k);
            bitset<nax> res;
            res.set();
            while (k--){
                int u, v;
                scanf ("%d %d", &u, &v);
                res &= get_path(u, v);
            }
            printf ("%d\n", res.count());
        }
    }
    return 0;
}


