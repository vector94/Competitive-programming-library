#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii     	            pair<int,int>
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define fastRead 	            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define eps     	            1e-10
#define FABS(x)                 ((x) + eps < 0 ? -(x) : (x))
#ifdef Lollipop
    #define line                    cout << "\n===================\n"
    #define trace(...)              __f( #__VA_ARGS__ , __VA_ARGS__ )
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " = " << arg1 << "\n";
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " = " << arg1 << " , ";
    __f(comma + 1, args...);
    }
#else
    #define line
    #define trace(...)
#endif

//int dx[] = {-1, 0, 1, 0},                  dy[] = {0, 1, 0, -1};                  // 4 Direction
//int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1},    dy[] = {0, 1, 0, -1, -1, 1, -1, 1};    // 8 Direction

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
ll MATMOD = 7;
struct MAT{
    ll a[3][3];
    int row, col;
    MAT(){}
    MAT(int r, int c){
        row = r;
        col = c;
        mem(a, 0);
    }
    void assign ( int r, int c ) {
        row = r;
        col = c;
    }
    void identity(){
        mem(a, 0);
        for ( int i = 0; i < row; i++ ) a[i][i] = 1;
    }
    void print() {
        for ( int i = 0; i < row; i++ ){
            for ( int j = 0; j < col; j++ ) printf ( "%llu ", a[i][j] );
            printf ( "\n" );
        }
    }
    MAT operator * ( MAT b ) {
        MAT res ( row, b.col );
        for ( int i = 0; i < row; i++ ){
            for ( int j = 0; j < b.col; j++ ){
                for ( int k = 0; k < col; k++ )
                    res.a[i][j] = ( res.a[i][j] + a[i][k] * b.a[k][j] ) % MATMOD;
            }
        }
        return res;
    }
    MAT operator ^ ( ll p ) {
        MAT res ( row, col ); res.identity();
        MAT x = *this;
        while ( p ){
            if ( p & 1 ){
                res = res * x;
            }
            x = x * x;
            p >>= 1;
        }
        return res;
    }
};

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int a, b, n;
    while (true){
        scanf("%d %d %d", &a, &b, &n);
        if (a == 0 && b == 0 && n == 0){
            break;
        }
        MAT A(2, 1);
        A.a[0][0] = 1;
        A.a[1][0] = 1;
        MAT B(2, 2);
        B.a[0][0] = 0;  B.a[0][1] = 1;
        B.a[1][0] = b;  B.a[1][1] = a;
        MAT res = (B ^ (n - 1)) * A;
        printf ("%lld\n", res.a[0][0]);
    }
    return 0;
}
