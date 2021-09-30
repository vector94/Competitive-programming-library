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
#define popcount            __builtin_popcountll
#define pii     	        pair<int,int>
#define all(x)              x.begin(), x.end()
#define uniq(x)             x.erase(unique(x.begin(),x.end()),x.end())
#define mem(array, value)   memset(array, value, sizeof(array))
#define lcm(a,b)            (abs(a)/gcd(a,b))*abs(b)
#define random(a, b)        ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define PI      	        2*acos(0.0)
#define INF     	        1e9
#define EPS     	        1e-8
#define line                cout << "\n==========\n"
#define fastRead 	        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;

ll mulmod(ll a, ll p, ll m){
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
            res = mulmod(res, x, m);
        }
        x = mulmod(x, x, m);
        p >>= 1;
    }
    return res;
}

bool miillerTest(ll d, ll n) 
{ 
    ll a = 2 + rand() % (n - 4);
    ll x = bigmod(a, d, n); 
  
    if (x == 1  || x == n-1){ 
        return true; 
    }
    while (d != n-1) 
    { 
        x = mulmod(x, x, n); 
        d *= 2; 
  
        if (x == 1){
            return false;
        } 
        if (x == n-1){
            return true;
        } 
    } 
    return false; 
} 

bool isPrime(ll n, int k) 
{ 
    if (n <= 1 || n == 4){
        return false;
    }
    if (n <= 3){
        return true;
    }
    ll d = n - 1; 
    while (d % 2 == 0){
        d /= 2;
    }
    for (int i = 0; i < k; i++){ 
        if (!miillerTest(d, n)){ 
            return false;
        }
    }
    return true; 
} 
  
int main() 
{ 
    /// Number of Iteration
    int k = 4;
  
    cout << "All primes smaller than 100: \n"; 
    for (int n = 1; n < 100; n++){ 
        if (isPrime(n, k)){
            cout << n << " ";
        }
    }
    return 0; 
} 


