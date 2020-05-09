
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
#define bitcount(number)        __builtin_popcount(number)
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

ll Set(ll num, int pos){
    return num | (1LL << pos);
}
bool Check(ll num, int pos){
    return (bool)(num & (1LL << pos));
}

const int inf = 1e8;
int node;
int graph[20][20];
int edge[20];

void floydWarshall()
{
    for (int k = 0; k < node; k++){
        for (int i = 0; i < node; i++){
            for (int j = 0; j < node; j++){
                if (graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

void init()
{
    for (int i = 0; i < node; i++){
        edge[i] = 0;
        for (int j = 0; j < node; j++){
            if (i == j){
                graph[i][j] = 0;
            }
            else{
                graph[i][j] = inf;
            }
        }
    }
}

int cs;
int dp[1 << 16], mark[1 << 16];

int solve(int mask)
{
    if (bitcount(mask) == node){
        return 0;
    }
    int &ret = dp[mask];
    int &m = mark[mask];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = inf;
    for (int i = 0; i < node; i++){
        if (!Check(mask, i)){
            for (int j = i + 1; j < node; j++){
                if (!Check(mask, j)){
                    int next_mask = mask;
                    next_mask = Set(next_mask, i);
                    next_mask = Set(next_mask, j);
                    ret = min(ret, graph[i][j] + solve(next_mask));
                }
            }
            break;
        }
    }
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    cin >> t;
    for (cs = 1; cs <= t; cs++){
        cin >> node;
        int m;
        cin >> m;
        init();
        int res = 0;
        while (m--){
            int u, v, w;
            cin >> u >> v >> w;
            res += w;
            u--;
            v--;
            edge[u]++;
            edge[v]++;
            graph[u][v] = min(graph[u][v], w);
            graph[v][u] = min(graph[v][u], w);
        }
        floydWarshall();
        int mask = 0;
        for (int i = 0; i < node; i++){
            if (edge[i] % 2 == 0){
                mask = Set(mask, i);
            }
        }
        res += solve(mask);
        printf ("Case %d: %d\n", cs, res);
    }
    return 0;
}

