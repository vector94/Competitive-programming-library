#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define ull                     unsigned long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii     	            pair<int,int>
#define popcount                __builtin_popcountll
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define lcm(a,b)                ((abs(a) / gcd(a,b)) * abs(b))
#define num_digit(number, base) (((long long)(log10(number) / log10(base)))+1)
#define SQ(x)                   ((x) * (x))
#define pi      	            (2 * acos(0.0))
#define eps     	            1e-11
#define line                    cout << "\n==========\n"
#define fastRead 	            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define trace(...)              __f( #__VA_ARGS__ , __VA_ARGS__ )
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

//int dx[] = {-1, 0, 1, 0},                  dy[] = {0, 1, 0, -1};                  // 4 Direction
//int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1},    dy[] = {0, 1, 0, -1, -1, 1, -1, 1};    // 8 Direction

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
inline ll big_mod(ll a, ll p, ll m){
    ll res = 1 % m, x = a % m;
    while (p){
        if (p & 1) res = (res * x) % m;
        x = (x * x) % m, p >>= 1;
    }
    return res;
}

const ll INF = 1e15;


/// If recurrence has k states. Its required (2 * k) terms of recurrence.
/// Assign SZ and mod
const int SZ;
const int mod; /// mod must be a prime
struct linear_recurrence_berlekamp_massey {
        ll m , a[SZ] , h[SZ] , t_[SZ] , s[SZ] , t[SZ];

        inline ll bigmod( ll b , ll p , ll mod ) {
            ll res = 1%mod , x = b%mod;
            while( p ) {
                if ( p&1 ) res = (res * x)%mod; x = (x * x)%mod; p >>= 1;
            }
            return (res%mod);
        }
        inline vector <ll> BM( vector <ll> &x ) {
            ll lf , ld;
            vector <ll> ls , cur;
            for( int i = 0; i < int(x.size()); ++i ) {
                ll t = 0;
                for( int j = 0; j < int(cur.size()); ++j ) t=(t + x[i-j-1] * cur[j])%mod;
                if( (t - x[i])%mod == 0 ) continue;
                if( !cur.size() ) {
                    cur.resize( i + 1 );
                    lf = i; ld = (t - x[i])%mod;
                    continue;
                }
                ll k = -(x[i] - t) * bigmod( ld , mod - 2 , mod )%mod;
                vector <ll> c(i - lf - 1);
                c.push_back( k );
                for( int j = 0; j < int(ls.size()); ++j ) c.push_back(-ls[j] * k%mod);
                if( c.size() < cur.size() ) c.resize( cur.size() );
                for( int j = 0; j < int(cur.size()); ++j ) c[j] = (c[j] + cur[j])%mod;
                if(i - lf + (int)ls.size() >= (int)cur.size() ) ls = cur, lf = i, ld = (t-x[i])%mod;
                cur = c;
            }
            for( int i = 0; i < int(cur.size()); ++i ) cur[i] = (cur[i]%mod + mod)%mod;
            return cur;
        }
        inline void mull( ll *p , ll *q ) {
            for( int i = 0;i < m + m; ++i ) t_[i] = 0;
            for( int i = 0; i < m; ++i ) if( p[i] )
                    for( int j = 0; j < m; ++j ) t_[i+j] = (t_[i+j] + p[i] * q[j])%mod;
            for( int i = m + m - 1; i >= m; --i ) if( t_[i] )
                    for( int j = m - 1; ~j; --j ) t_[i-j-1] = (t_[i-j-1] + t_[i] * h[j])%mod;
            for( int i = 0; i < m; ++i ) p[i] = t_[i];
        }
        inline ll calc( ll K ){
            for( int i = m; ~i; --i ) s[i] = t[i] = 0;
            s[0] = 1; if( m != 1 ) t[1] = 1; else t[0] = h[0];
            while( K ) {
                if( K&1 ) mull( s , t );
                mull( t , t ); K >>= 1;
            }
            ll su = 0;
            for( int i = 0; i < m; ++i ) su = (su + s[i] * a[i])%mod;
            return (su%mod + mod)%mod;
        }
        /// already calculated upto k , now calculate upto n.
        inline vector <ll> process( vector <ll> &x , int n , int k ) {
            auto re = BM( x );
            x.resize( n+1 );
            for( int i = k + 1; i <= n; i++ ){
                for( int j = 0; j < re.size(); j++ ){
                    x[i] += 1ll * x[i - j - 1]%mod * re[j] % mod; x[i] %= mod;
                }
            }
            return x;
        }
        inline ll work( vector <ll> &x , ll n ) {
            if( n < int(x.size()) ) return x[n]%mod;
            vector <ll> v = BM( x ); m = v.size(); if( !m ) return 0;
            for( int i = 0; i < m; ++i ) h[i] = v[i], a[i] = x[i];
            return calc( n )%mod;
        }
} rec;


int main ()
{
    #ifdef Lollipop
        //freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;

    vector<ll> v;
    /// Fibonacci Series
    v.pb(1);
    v.pb(1);
    v.pb(2);
    v.pb(3);

    int n;
    cin >> n;
    ll ans = rec.work(v, n - 1);
    cout << ans << endl;
    return 0;
}
