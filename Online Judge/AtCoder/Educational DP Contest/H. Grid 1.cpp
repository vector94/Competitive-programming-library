#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll                  long long int
#define ull                 unsigned long long int
#define ld                  long double
#define fi                  first
#define se                  second
#define pb                  push_back
#define pbb                 pop_back
#define mp                  make_pair
#define popcount            __builtin_popcountll
#define pii     	        pair<int,int>
#define all(x)              x.begin(), x.end()
#define uniq(x)             x.erase(unique(x.begin(),x.end()),x.end())
#define mem(array, value)   memset(array, value, sizeof(array))
#define lcm(a,b)            (abs(a)/gcd(a,b))*abs(b)
#define random(a, b)        ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define PI      	        2*acos(0.0)
#define EPS     	        1e-8
#define line                cout << "\n==========\n"
#define fastRead 	        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define trace(...)          __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " , ";
    __f(comma + 1, args...);
}
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;

//int dx[] = {1, -1, 0, 0},                  dy[] = {0, 0, 1, -1};                  // 4 Direction
//int dx[] = {1, -1, 0, 0, 1, 1, -1, -1},    dy[] = {0, 0, 1, -1, 1, -1, 1, -1};    // 8 Direction
//int dx[] = {1, -1, 1, -1, 2, 2, -2, -2},   dy[] = {2, 2, -2, -2, 1, -1, 1, -1};   // Knight Direction

inline ll gcd(ll a, ll b){
    a = abs(a);
    b = abs(b);
    while (b){
        a = a % b;
        swap (a, b);
    }
    return a;
}
inline ll power(ll a, ll p){
    ll res = 1, x = a;
    while (p){
        if (p & 1){
            res = (res * x);
        }
        x = (x * x);
        p >>= 1;
    }
    return res;
}
inline ll mulmod(ll a, ll p, ll m){
    ll res = 0, x = a%m;
    while (p){
        if (p & 1){
            res = (res + x) % m;
        }
        x = (x << 1) % m;
        p >>= 1;
    }
    return res;
}
inline ll bigmod(ll a, ll p, ll m){
    ll res = 1 % m, x = a % m;
    while (p){
        if (p & 1){
            res = (res * x) % m;
        }
        x = (x * x) % m;
        p >>= 1;
    }
    return res;
}

const int INF = 1e9+9;

const int mod = 1e9+7;
const int nax = 1009;
char grid[nax][nax];
int dp[nax][nax];

void add_self(int& a, int b)
{
    a += b;
    if (a >= mod){
        a -= mod;
    }
}

int main ()
{
    #ifdef Lollipop
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    #endif
    int h, w;
    cin >> h >> w;
    for (int row = 0; row < h; row++){
        for (int col = 0; col < w; col++){
            cin >> grid[row][col];
        }
    }
    dp[0][0] = 1;
    for (int row = 0; row < h; row++){
        for (int col = 0; col < w; col++){
            for (int r2: {row, row+1}){
                int c2 = col;
                if (r2 == row){
                    c2 = col+1;
                }
                if (r2 < h && c2 < w && grid[r2][c2] == '.'){
                    add_self(dp[r2][c2], dp[row][col]);
                }
            }
        }
    }
    cout << dp[h-1][w-1] << endl;
    return 0;
}
