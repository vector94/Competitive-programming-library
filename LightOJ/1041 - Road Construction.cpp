#include <bits/stdc++.h>
#define ll                  long long int
#define ull                 unsigned long long int
#define ld                  long double
#define fi                  first
#define se                  second
#define pb                  push_back
#define pbb                 pop_back
#define mp                  make_pair
#define pii     	        pair<int,int>
#define all(x)              x.begin(), x.end()
#define uniq(x)             x.erase(unique(x.begin(),x.end()),x.end())
#define mem(array, value)   memset(array, value, sizeof(array))
#define lcm(a,b)            (abs(a)/gcd(a,b))*abs(b)
#define PI      	        acos(-1.0)
#define INF     	        1e9
#define EPS     	        1e-8
#define MOD                 1000000007
#define MAX                 1000009
#define line                cout << "\n==========\n"
#define fastRead 	        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

//int dx4[4] = {0, -1, 0, 1};
//int dy4[4] = {-1, 0, 1, 0};
//int dx8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
//int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

inline ll gcd ( ll a, ll b ) {
    a = abs ( a ); b = abs ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

inline ll power ( ll a, ll p ) {
    ll res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}

inline ll bigmod ( ll a, ll p, ll m ) {
    ll res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}
/// <----------------------------------------------------------------------> ///
int node;
vector<pii> adjList[109];

int solve(int src)
{
    priority_queue<pii, vector<pii>, greater<pii> > PQ;
    vector<int> key(109, INF);
    vector<int> parent(109, -1);
    vector<bool> inMST(109, false);

    PQ.push(mp(0, src));
    key[src] = 0;

    while (!PQ.empty()){
        int u = PQ.top().se;
        PQ.pop();
        inMST[u] = true;

        for(int i = 0; i<adjList[u].size(); i++){
            int v = adjList[u][i].fi;
            int weight = adjList[u][i].se;
            if (inMST[v] == false && key[v] > weight){
                key[v] = weight;
                PQ.push(mp(key[v], v));
                parent[v] = u;
            }
        }
    }
    int ans = 0;
    for (int i = 1;i<=node; i++){
        if (!inMST[i]){
            return -1;
        }
        ans += key[i];
    }
    return ans;
}
int main ()
{
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    int t;
    cin >> t;
    for (int cs = 1; cs<=t; cs++){
        int m;
        cin >> m;
        string city1, city2;
        int cost;
        map<string, int> Hash;
        node = 0;
        while (m--){
            cin >> city1 >> city2 >> cost;
            if (Hash.find(city1) == Hash.end()){
                Hash[city1] = ++node;
            }
            if (Hash.find(city2) == Hash.end()){
                Hash[city2] = ++node;
            }
            int u, v;
            u = Hash[city1];
            v = Hash[city2];
            adjList[u].pb(mp(v, cost));
            adjList[v].pb(mp(u, cost));
        }
        int ans = solve(1);
        if (ans == -1){
            printf ("Case %d: Impossible\n", cs);
        }
        else {
            printf ("Case %d: %d\n", cs, ans);
        }

        for (int i = 0; i<109; i++){
            adjList[i].clear();
        }
    }
    return 0;
}

