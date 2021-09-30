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
#define endl                    "\n"
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
        cerr.write(names, comma - names) << " = " << arg1 << " , ";
    __f(comma + 1, args...);
    }
#else
    #define line
    #define trace(...)
#endif
#define bitcount(number)        __builtin_popcount(number)
inline ll power(ll a, ll p){
    ll res = 1, x = a;
    while (p){
        if (p & 1) res = (res * x);
        x = (x * x), p >>= 1;
    }
    return res;
}

ll Set(ll num, int pos){
    return num | (1LL << pos);
}
bool Check(ll num, int pos){
    return (bool)(num & (1LL << pos));
}

int base, k, cs, n;
string s;
ll dp[(1 << 16) + 5][22];
int mark[(1 << 16) + 5][22];

ll get_num(char ch)
{
    if (ch >= '0' && ch <= '9'){
        return ch - '0';
    }
    return ch - 'A' + 10;
}

ll solve(int mask, int rem)
{
    if (bitcount(mask) == n){
        return (rem == 0);
    }
    ll &ret = dp[mask][rem];
    int &m = mark[mask][rem];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 0;
    for (int i = 0; i < n; i++){
        if (!Check(mask, i)){
            ret += solve(Set(mask, i), (rem * base + get_num(s[i])) % k);
        }
    }
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    cin >> t;
    for (cs = 1; cs <= t; cs++){
        cin >> base >> k;
        cin >> s;
        n = s.size();
        printf ("Case %d: %lld\n", cs, solve(0, 0));
    }
    return 0;
}

