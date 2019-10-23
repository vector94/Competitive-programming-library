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
vector<int> adjList[10009];
vector<int> topSort;
int visit[10009];

void TopSort(int src)
{
    visit[src] = 1;
    for (int i = 0; i<adjList[src].size(); i++){
        int x = adjList[src][i];
        if (!visit[x]){
            TopSort(x);
        }
    }
    topSort.pb(src);
}
void dfs(int src)
{
    visit[src] = 1;
    for (int i = 0; i<adjList[src].size(); i++){
        int x = adjList[src][i];
        if (!visit[x]){
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
    for (int cs = 1; cs<=t; cs++){
        int m;
        cin >> node >> m;
        for (int i = 1; i<=node; i++){
            adjList[i].clear();
        }
        int u, v;
        while (m--){
            cin >> u >> v;
            adjList[u].pb(v);
        }
        mem(visit, 0);
        topSort.clear();
        for (int i = 1; i<=node; i++){
            if (!visit[i]){
                TopSort(i);
            }
        }
        int ans = 0;
        mem(visit, 0);
        for (int i = topSort.size()-1; i>=0; i--){
            if (!visit[topSort[i]]){
                dfs(topSort[i]);
                ans++;
            }
        }
        printf ("Case %d: %d\n", cs, ans);
    }
    return 0;
}
