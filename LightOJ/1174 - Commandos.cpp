#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define pbb pop_back
#define make_pair mp
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(x.begin(),x.end()),x.end())
#define mem(array, value) memset(array, value, sizeof(array))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a,b))*b
#define line cout << "\n==========\n"
#define mod 1000000007
#define SIZE 1000001

int node;
vector<int> adjList[109];
int level1[109];
int level2[109];
int visit[109];

void bfs(int src, int *level){
    mem(visit, 0);
    queue<int> Q;
    Q.push(src);
    visit[src] = 1;
    while (!Q.empty()){
        int x = Q.front();
        Q.pop();
        for (int i = 0; i<adjList[x].size(); i++){
            int y = adjList[x][i];
            if (!visit[y]){
                visit[y] = 1;
                level[y] = level[x]+1;
                Q.push(y);
            }
        }
    }
}


int main ()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for (int cs = 1; cs<=t; cs++){
        for (int i = 0; i<100; i++){
            adjList[i].clear();
        }
        int road;
        cin >> node;
        cin >> road;
        int u, v;
        while (road--){
            cin >> u >> v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        int src, dst;
        cin >> src >> dst;
        mem(level1, 0);
        mem(level2, 0);
        bfs(src, level1);
        bfs(dst, level2);
        int ans = -1;
        for (int i = 0; i<node; i++){
            ans = max(ans, level1[i] + level2[i]);
        }
        printf ("Case %d: %d\n", cs, ans);
    }
    return 0;
}
