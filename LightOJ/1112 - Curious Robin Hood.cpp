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

const int nax = 1e5+5;
int ara[nax];
int tree[nax * 3];

void init(int node, int b, int e)
{
    if (b == e){
        tree[node] = ara[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b){
        return 0;
    }
    if (b >= i && e <= j){
        return tree[node];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);
    return p1 + p2;
}

void update(int node, int b, int e, int i, int new_value)
{
    if (i > e || i < b){
        return;
    }
    if ( b >= i && e <= i){
        tree[node] += new_value;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e)/2;
    update(left, b, mid, i, new_value);
    update(right, mid+1, e, i, new_value);
    tree[node] = tree[left] + tree[right];
}

int main ()
{
    #ifdef Lollipop
    freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    #endif
    
    int t;
    scanf ("%d", &t);
    for (int cs = 1; cs <= t; cs++){
        int n, q;
        scanf ("%d %d", &n, &q);
        for (int i = 0;i <n; i++){
            scanf ("%d", &ara[i]);
        }
        init(1, 0, n-1);
        printf ("Case %d:\n", cs);
        while (q--){
            int task;
            scanf ("%d", &task);
            if (task == 1){
                int idx;
                scanf ("%d", &idx);
                printf ("%d\n", ara[idx]);
                update(1, 0, n-1, idx, -ara[idx]);
                ara[idx] = 0;
            }
            else if (task == 2){
                int value, idx;
                scanf ("%d %d", &idx, &value);
                update(1, 0, n-1, idx, value);
                ara[idx] += value;
            }
            else{
                int l, r;
                scanf ("%d %d", &l, &r);
                printf ("%d\n", query(1, 0, n-1, l, r));
            }
        }
    }
    return 0;
}
