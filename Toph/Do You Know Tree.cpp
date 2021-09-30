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

const int nax = 1e6 + 5;
vector<pii> graph[nax];
multiset<ll> branch[nax];
int n;

ll dfs1(int u, int p)
{
    for (auto x : graph[u]){
        int v = x.fi;
        ll w = x.se;
        if (v == p) continue;
        ll cur = w + dfs1(v, u);
        branch[u].insert(cur);
    }
    return *branch[u].rbegin();
}

void dfs2(int u, int p)
{
    for (auto x : graph[u]){
        int v = x.fi;
        ll w = x.se;
        if (v == p) continue;
        auto it1 = branch[u].rbegin();
        auto it2 = branch[v].rbegin();
        if (*it1 == *it2 + w){
            it1++;
        }
        branch[v].insert(*it1 + w);
        dfs2(v, u);
    }
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    scanf ("%d", &n);
    for (int i = 1; i < n; i++){
        int u, v;
        ll w;
        scanf ("%d %d %lld", &u, &v, &w);
        graph[u].pb(mp(v, w));
        graph[v].pb(mp(u, w));
    }
    branch[1].insert(0);
    for (int i = 1; i <= n; i++){
        branch[i].insert(0);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int q;
    scanf ("%d", &q);
    while (q--){
        int x;
        scanf ("%d", &x);
        auto it = branch[x].rbegin();
        ll res = *it;
        it++;
        res += *it;
        printf ("%lld\n", res);
    }
    return 0;
}

