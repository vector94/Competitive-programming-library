#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii     	            pair<int,ll>
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define endl                    "\n"
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

const int nax = 3e4 + 5;
vector<pii> graph[nax];
int dis1[nax], dis2[nax];
int node;
int mx, leaf;

int dfs1(int u, int p)
{
    for (auto it : graph[u]){
        int v = it.fi;
        ll w = it.se;
        if (v == p){
            continue;
        }
        dis1[v] = w + dis1[u];
        dfs1(v, u);
    }
    if (dis1[u] > mx){
        mx = dis1[u];
        leaf = u;
    }
}

int dfs2(int u, int p)
{
    for (auto it : graph[u]){
        int v = it.fi;
        ll w = it.se;
        if (v == p){
            continue;
        }
        dis2[v] = w + dis2[u];
        dfs2(v, u);
    }
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", " r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    scanf ("%d", &t);
    for (int cs = 1; cs <= t; cs++){
        scanf ("%d", &node);
        for (int i = 1; i < node; i++){
            int u, v;
            ll w;
            scanf ("%d %d %lld", &u, &v, &w);
            u++;
            v++;
            graph[u].pb(mp(v, w));
            graph[v].pb(mp(u, w));
        }
        mx = 0;
        dfs1(1, 0);
        for (int i = 1; i <= node; i++){
            dis1[i] = 0;
        }
        mx = 0;
        dfs1(leaf, 0);
        dfs2(leaf, 0);
        printf ("Case %d:\n", cs);
        for (int i = 1; i <= node; i++){
            ll res = max(dis1[i], dis2[i]);
            printf ("%lld\n", res);
        }
        for (int i = 1; i <= node; i++){
            graph[i].clear();
            dis1[i] = 0;
            dis2[i] = 0;
        }
    }
    return 0;
}
