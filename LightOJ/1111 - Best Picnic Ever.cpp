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

int visit[1009];
vector<int> adjList[1009];
bool color[1009];

void dfs(int node)
{
    visit[node]++;
    color[node] = 1;
    for (int i = 0; i<adjList[node].size(); i++){
        int x = adjList[node][i];
        if (!color[x]){
            dfs(x);
        }
    }
}

int main ()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        mem(visit, 0);
        int k, n, m;
        cin >> k >> n >> m;
        int people[k];
        for (int i = 0; i<k; i++){
            cin >> people[i];
        }
        for (int i = 1; i<=n; i++){
            adjList[i].clear();
        }
        while (m--){
            int u, v;
            cin >> u >> v;
            adjList[u].pb(v);
        }
        for (int i = 0; i<k; i++){
            dfs(people[i]);
            mem(color, 0);
        }
        int ans = 0;
        for (int i = 1; i<=n; i++){
            if (visit[i] == k){
                ans++;
            }
        }
        printf ("Case %d: %d\n", cs, ans);
    }
    return 0;
}
