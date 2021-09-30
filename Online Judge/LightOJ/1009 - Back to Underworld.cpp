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

int red, blue, ans;
int color[20009];
vector<int> adjList[20009];

void bfs()
{
    ans = 0;
    mem(color, 0);
    queue<int> Q;

    for (int i = 1; i<=20000; i++){
        if (!color[i] && !adjList[i].empty()){
            red = blue = 0;
            Q.push(i);
            color[i] = 1;
            red++;
            while (!Q.empty()){
                int x = Q.front();
                Q.pop();
                for (int i = 0; i<adjList[x].size(); i++){
                    int y = adjList[x][i];
                    if (!color[y]){
                        if (color[x] == 1){
                            color[y] = 2;
                            blue++;
                        }
                        else {
                            color[y] = 1;
                            red++;
                        }
                        Q.push(y);
                    }
                }
            }
            ans += max(red, blue);
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
        for (int i = 1; i<=20000; i++){
            adjList[i].clear();
        }
        int n;
        cin >> n;
        int u, v;
        for (int i = 0; i<n; i++){
            cin >> u >> v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        bfs();
        printf ("Case %d: %d\n", cs, ans);
    }
    return 0;
}
