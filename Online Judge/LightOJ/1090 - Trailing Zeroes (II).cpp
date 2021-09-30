#include <bits/stdc++.h>
#define ll                  long long int
#define ull                 unsigned long long int
#define ld                  long double
#define fi                  first
#define se                  second
#define pb                  push_back
#define pbb                 pop_back
#define mp                  make_pair
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
/// <--------------------------X--------------------------> ///

int cal(int n, int x)
{
    int res = 0;
    for (int i = x; i<=n; i*=x){
        res += n/i;
    }
    return res;
}

int cnt(int n, int x)
{
    int res = 0;
    while (n%x == 0){
        n/=x;
        res++;
    }
    return res;
}

int main ()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int cs = 1; cs<=t; cs++){
        int n, r, p, q;
        cin >> n >> r >> p >> q;
        ll two, five;
        two = cal(n, 2) - cal(r, 2) - cal(n-r, 2) + q*cnt(p, 2);
        five = cal(n, 5) - cal(r, 5) - cal(n-r, 5) + q*cnt(p, 5);
        printf ("Case %d: %d\n",cs, min(two , five));
    }

    return 0;
}


