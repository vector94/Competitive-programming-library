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

struct Hashing {
    ll *hash1, *hash2;
    ll *inv1, *inv2;
    int n;
    ll mod1 = (ll) 1e9 + 97, mod2 = (ll) 1e9 + 9;
    ll multiplier1 = 43, multiplier2 = 31;
    ll invMultiplier1 = 441860508, invMultiplier2 = 838709685;
    Hashing() {}
    Hashing(string &s) {
        build_hash(s);
    }
    void build_hash(string &s) {
        n = s.size();
        hash1 = new ll[n + 1];
        hash2 = new ll[n + 1];
        inv1 = new ll[n + 1];
        inv2 = new ll[n + 1];
        hash1[0] = hash2[0] = 0;
        inv1[0] = inv2[0] = 1;
        ll p1 = 1, p2 = 1;
        for (int i = 0; i < n; i++) {
            hash1[i + 1] = (hash1[i] + s[i] * p1) % mod1;
            p1 = (p1 * multiplier1) % mod1;
            inv1[i + 1] = inv1[i] * invMultiplier1 % mod1;
            hash2[i + 1] = (hash2[i] + s[i] * p2) % mod2;
            p2 = (p2 * multiplier2) % mod2;
            inv2[i + 1] = inv2[i] * invMultiplier2 % mod2;
        }
    }
    ll get_hash(int i, int j) {                 /// 0 - based, hash of substring [i, j]
        return get_hash2(i, j - i + 1);
    }
    ll get_hash2(int i, int len) {              /// 0 - based, hash of substring [i, i+len-1]
        return (((hash1[i + len] - hash1[i] + mod1) * inv1[i] % mod1) << 32)
                                + (hash2[i + len] - hash2[i] + mod2) * inv2[i] % mod2;
    }
    ll rev_hash(int i, int j) {                 /// 0 - based [not hash of reverse string]
        return get_hash(n - j - 1, n - i - 1);
    }
    void clear() {
        delete (hash1);
        delete (hash2);
        delete (inv1);
        delete (inv2);
    }
};
Hashing fhash, rhash;

const int nax = 1e3 + 5;
int dp[nax][nax], mark[nax][nax];
string s, r;
int cs, sz;

int solve(int pre, int cur)
{
    if (cur == sz){
        if (pre == cur) return 0;
        return nax;
    }
    int &ret = dp[pre][cur];
    if (mark[pre][cur] == cs)   return ret;
    mark[pre][cur] = cs;
    ret = nax;
    if (fhash.get_hash(pre, cur) == rhash.rev_hash(pre, cur)){
        ret = min(ret, 1 + solve(cur + 1, cur + 1));
    }
    ret = min(ret, solve(pre, cur + 1));
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;
    int t;
    cin >> t;
    for (cs = 1; cs <= t; cs++){
        cin >> s;
        r = s;
        reverse(all(r));
        fhash.build_hash(s);
        rhash.build_hash(r);
        sz = s.size();
        printf ("Case %d: %d\n", cs, solve(0, 0));
    }
    return 0;
}

