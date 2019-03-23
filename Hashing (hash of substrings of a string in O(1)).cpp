#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
#define EPS     	        1e-8
#define line                cout << "\n==========\n"
#define fastRead 	        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;

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
    ll get_hash(int i, int j) { 
        return get_hash2(i, j - i + 1);
    }
    ll get_hash2(int i, int len) {
        return (((hash1[i + len] - hash1[i] + mod1) * inv1[i] % mod1) << 32) 
                                + (hash2[i + len] - hash2[i] + mod2) * inv2[i] % mod2;
    }
    ll rev_hash(int i, int j) {
        return get_hash(n - j - 1, n - i - 1);
    }
    void clear() {
        delete (hash1);
        delete (hash2);
        delete (inv1);
        delete (inv2);
    }
};
Hashing hashing;

int main ()
{
    #ifdef Lollipop
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    #endif
	    
    string str;
    cin >> str;

    hashing.build_Hash(str);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        ll h = hashing.get_hash(a, b);
        ll r = hashing.rev_hash(a, b);
        cout << "get_hash = " << h << ", rev_hash = " << r << endl;
    }
    return 0;
}
