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
/// <----------------------------------------------------> ///

bool sieve[MAX];
vector<int> primes;

void cal()
{
    int sqrtN = sqrt(MAX);
    for (int i = 3; i<=sqrtN; i+=2){
        if (!sieve[i]){
            for (int j = i*i; j<=MAX; j+= 2*i){
                sieve[j] = 1;
            }
        }
    }
    primes.pb(2);
    for (int i = 3; i<=MAX; i+=2){
        if (!sieve[i]){
            primes.pb(i);
        }
    }
}

int NOD(int num)
{
    ll res = 1;
    ll sqrtN = sqrt(num);
    for (int i = 0; i < primes.size() && primes[i] <= sqrtN; i++){
        if (num % primes[i] == 0){
            int p = 0;
            while (num%primes[i] == 0){
                num/=primes[i];
                p++;
            }
            p++;
            sqrtN = sqrt(num);
            res *= p;
        }
    }
    if (num != 1){
        res*= 2;
    }
    return res-1;
}

int main ()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    cal();
    int t;
    cin >> t;
    for (int cs = 1; cs<=t; cs++){
        ll n;
        cin >> n;
        printf ("Case %d: %d\n", cs, NOD(n));
    }

    return 0;
}


