#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#define ll                      long long int
#define ull                     unsigned long long int
#define ld                      long double
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii     	            pair<int,int>
#define piii                    pair<pair<int, int>, int>
#define bitcount(number)        __builtin_popcount(a)
#define bitcountLL(number)      __builtin_popcountll(a)
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define lcm(a,b)                ((abs(a) / gcd(a,b)) * abs(b))
#define num_digit(number, base) (((long long)(log10(number) / log10(base))) + 1)
#define Random(a, b)            ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define Unique(x)               x.erase(unique(x.begin(), x.end()), x.end())                            /// data must be sorted
#define Common(x, y)            x.erase(set_intersection(all(x), all(y), x.begin()), x.end())           /// data must be sorted
#define Uncommon(x, y)          x.erase(set_symmetric_difference(all(x), all(y), x.begin()), x.end())   /// data must be sorted
#define Binary(number, digit)   bitset<digit>( number ).to_string()
#define FABS(x)                 ((x) + eps < 0 ? -(x) : (x))
#define SQ(x)                   ((x) * (x))
#define pi      	            (2 * acos(0.0))
#define eps     	            1e-11
#define line                    cout << "\n====================\n"
#define fastRead 	            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#ifdef Lollipop
    #define trace(...)              __f( #__VA_ARGS__ , __VA_ARGS__ )
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " = " << arg1 << "\n";
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1 << " , ";
    __f(comma + 1, args...);
    }
#else
    #define trace(...)
#endif
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;

//int dx[] = {-1, 0, 1, 0},                  dy[] = {0, 1, 0, -1};                  /// 4 Direction
//int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1},    dy[] = {0, 1, 0, -1, -1, 1, -1, 1};    /// 8 Direction
//int dx[] = {-2, -1, 1, 2, 2, -1, 1, -2},   dy[] = {1, 2, 2, 1, -1, -2, -2, -1};   /// Knight Direction

/// Priority Queue custom compare
//#define PQ_TYPE pair<pair<ll,ll>,int>
//bool cmp(const PQ_TYPE &a, const PQ_TYPE &b){
//    return a.fi.fi * b.fi.se < b.fi.fi * a.fi.se;
//}
//std::priority_queue< PQ_TYPE , std::vector< PQ_TYPE >, decltype(&cmp) > PQ(cmp);

int Set(int mask, int pos){
    return mask | (1 << pos);
}
int Reset(int mask, int pos){
    return mask & ~(1 << pos);
}
bool Check(int mask, int pos){
    return (bool)(mask & (1 << pos));
}

inline ll gcd(ll a, ll b){
    a = abs(a), b = abs(b);
    while (b)
        a = a % b, swap (a, b);
    return a;
}
inline ll power(ll a, ll p){
    ll res = 1, x = a;
    while (p){
        if (p & 1) res = (res * x);
        x = (x * x), p >>= 1;
    }
    return res;
}
inline ll mul_mod(ll a, ll p, ll m){
    ll res = 0, x = a%m;
    while (p){
        if (p & 1) res = (res + x) % m;
        x = (x << 1) % m, p >>= 1;
    }
    return res;
}
inline ll big_mod(ll a, ll p, ll m){
    ll res = 1 % m, x = a % m;
    while (p){
        if (p & 1) res = (res * x) % m;
        x = (x * x) % m, p >>= 1;
    }
    return res;
}
ll ext_gcd(ll A, ll B, ll *X, ll *Y ){
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1, y2 = 0;
    x1 = 0, y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1, r = r2 % r1;
        x = x2 - (q * x1), y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}
inline ll mod_inv(ll a, ll m){
    ll x, y;
    ext_gcd(a, m, &x, &y);
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

const ll INF = 1e15;


int main ()
{
    #ifdef Lollipop
        //freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;



    return 0;
}
