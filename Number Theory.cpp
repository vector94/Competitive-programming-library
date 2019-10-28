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
        cerr.write(names, comma - names) << " : " << arg1 << " , ";
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

/// ------------------------- Sieve of Eratosthenes ------------------------- ///
/// Assign N
const int N;
bool sieve[N + 5];
vector<int> primes;
void gen_prime(){
    int sqrtN = sqrt(N);
    for (int i = 3; i <= sqrtN; i+= 2){
        if (!sieve[i]){
            for (int j = i * i; j <= N; j += 2 * i){        /// i * i may overflow
                sieve[j] = true;
            }
        }
    }
    primes.pb(2);
    for (int num = 3; num <= N; num+= 2){
        if (!sieve[num]){
            primes.pb(num);
        }
    }
}

/// Segmented Sieve
/// Find the primes between range u to v
/// Works when u, v <= 1e18 but (v - u) <= 1e6
/// Store first 5000 primes excluding 2
/// Assign rngSize
const int rngSize;
int segment[rngSize / 64];
#define checkC(x, n)                (x[n >> 6] & (1 << ((n >> 1) & 31)))
#define setC(x, n)                  (x[n >> 6] != (1 << ((n >> 1) & 31)))
void segmented_sieve(int a, int b){
    if (a <= 2 && 2 <= b){
        printf ("2\n");                 /// prime
    }
    if (b < 2)      return;
    if (a < 3)      a = 3;
    if (a % 2 == 0) a++;
    mem(segment, 0);
    for (int i = 0, limit = primes.size(); i < limit && (primes[i] * primes[i]) <= b; i++){
        unsigned j = primes[i] * ((a + primes[i] - 1) / primes[i]);
        if (j % 2 == 0)     j += primes[i];
        for (int k = (primes[i] << 1); j <= b; j += k){
            if (j != primes[i]){
                setC(segment, (j - a));
            }
        }
    }
    for (int i = 0; i <= b - a; i += 2){
        if (checkC(segment, i)){
            printf ("%d\n", i + a);     /// prime;
        }
    }
}

/// ------------------------- Prime Factorization ------------------------- ///
/// Generate primes upto sqrt(num) using sieve
/// Returns a vector consists of prime factors
vector<int> prime_factors(int num){
    vector<int> ret;
    int sqrtN = sqrt(num);
    for (int i = 0, limit = primes.size(); i < limit && primes[i] <= sqrtN; i++){
        if (num % primes[i] == 0){
            ret.pb(primes[i]);
            num /= primes[i];
            while (num % primes[i] == 0){
                num /= primes[i];
            }
            sqrtN = sqrt(num);
        }
    }
    if (num > 1){
        ret.pb(num);
    }
    return ret;
}

/// Generate primes upto sqrt(num) using sieve
/// Returns a vector consists of pairs(prime, count of prime)
vector<pair<int, int> > prime_fact(int num){
    vector<pair<int, int> > ret;
    int sqrtN = sqrt(num);
    for (int i = 0, limit = primes.size(); i < limit && primes[i] <= sqrtN; i++){
        if (num % primes[i] == 0){
            int cnt = 0;
            while (num % primes[i] == 0){
                cnt++;
                num /= primes[i];
            }
            ret.pb(mp(primes[i], cnt));
            sqrtN = sqrt(num);
        }
    }
    if (num > 1){
        ret.pb(mp(num, 1));
    }
    return ret;
}

/// Generate primes upto num using sieve
void factorial_factorize(int num){
    for (int i = 0, limit = primes.size(); i < limit && primes[i] <= num; i++){
        int x = num;
        int freq = 0;
        while (x / primes[i]){
            freq += x / primes[i];
            x /= primes[i];
        }
        printf ("%d^%d\n", primes[i], freq);
    }
}

/// ------------------------ Number of Divisor ------------------------ ///
/// Assign N
/// precalculate NOD upto limit
const int N;
int NOD[N];
void NOD_loop(int limit){
    for (int i = 1; i <= limit; i++){
        for (int j = i; j <= limit; j += i){
            NOD[j]++;
        }
    }
}

/// NOD of num using prime factorization
/// Generate prime upto sqrt(num) using sieve
inline int NOD_sieve(ll num){
    ll sqrtN = sqrt(num);
    ll ret = 1;
    for (int i = 0, limit = primes.size(); i < limit && primes[i] <= sqrtN; i++){
        if (num % primes[i] == 0){
            ll cnt = 0;
            while (num % primes[i] == 0){
                num /= primes[i];
                cnt++;
            }
            sqrtN = sqrt(num);
            cnt++;
            ret *= cnt;
        }
    }
    if (num != 1){
        ret *= 2;
    }
    return ret;
}

/// ------------------------- Sum of Divisor ------------------------- ///
/// Assign N
/// Precalculate SOD upto limit
const int N;
ll SOD[N];
void SOD_loop(int limit){
    for (int i = 1; i <= limit; i++){
        for (int j = i; j <= limit; j += i){
            SOD[j] += i;
        }
    }
}

/// SOD of num using prime factorization
/// Generate prime upto sqrt(num) using sieve
ll SOD_sieve(ll num){
    ll res = 1;
    ll sqrtN = sqrt(num);
    for (int i = 0, limit = primes.size(); i < limit && primes[i] <= sqrtN; i++){
        if (num % primes[i] == 0){
            ll temp_sum = 1;
            ll p = 1;
            while (num % primes[i] == 0){
                num /= primes[i];
                p *= primes[i];
                temp_sum += p;
            }
            sqrtN = sqrt(num);
            res *= temp_sum;
        }
    }
    if (num != 1){
        res *= (num + 1);
    }
    return res;
}

/// -------------------------- String MOD -------------------------- ///
ll string_mod(string s, ll m){
    ll ret = 0;
    for (int i = 0, sz = s.size(); i < sz; i++){
        ret = ((ret % m * 10) % m + (s[i] - '0') % m) % m;
    }
    return ret;
}

int main ()
{
    #ifdef Lollipop
        //freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;

    cout << string_mod("123456", 100);

    return 0;
}
