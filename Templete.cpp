#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
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
#define PI      	        2*acos(0.0)
#define INF     	        1e9
#define EPS     	        1e-8
#define line                cout << "\n==========\n"
#define fastRead 	        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
//using namespace __gnu_pbds;
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

int main ()
{
    #ifdef Lollipop
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    #endif // Lollipop
    
    return 0;
}
