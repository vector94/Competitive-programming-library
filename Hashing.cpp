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

const int nax = 1e5+5;
const int Mod[2] = {1000000007, 1000000009};
const int Base[2] = {31, 37};
ll Pow[nax][2];
string S;
int Len;
ll HashF[nax][2], HashR[nax][2];

void build_hash()
{
    Len = S.size();
    HashF[0][0] = 0, HashR[Len+1][0] = 0;
    HashF[0][1] = 0, HashR[Len+1][1] = 0;
    for (int i = 1; i <= Len; i++){
        HashF[i][0] = (HashF[i-1][0] * Base[0] + S[i-1]) % Mod[0];
        HashR[Len-i+1][0] = (HashR[Len-i+2][0] * Base[0] + S[Len-i]) % Mod[0];
        HashF[i][1] = (HashF[i-1][1] * Base[1] + S[i-1]) % Mod[1];
        HashR[Len-i+1][1] = (HashR[Len-i+2][1] * Base[1] + S[Len-i]) % Mod[1];
    }
}
ll get_hash(int l, int r) // 0 - based, hash of substring [l, r]
{
    l++, r++;
    if (l == 1) return (HashF[r][0] << 31) | HashF[r][1];
    ll Hash1 = (HashF[r][0] - HashF[l-1][0] * Pow[r-l+1][0] % Mod[0]);
    Hash1 = (Hash1 + Mod[0]) % Mod[0];
    ll Hash2 = (HashF[r][1] - HashF[l-1][1] * Pow[r-l+1][1] % Mod[1]);
    Hash2 = (Hash2 + Mod[1]) % Mod[1];
    return (Hash1 << 31) | Hash2;
}
ll get_hash2(int l, int len) // 0 - based, hash of substring [l, l+len-1]
{
    return get_hash(l, l+len-1);
}
ll rev_hash(int l, int r)
{
    l++, r++;
    if (r == Len) return (HashR[l][0] << 31) | HashR[l][1];
    ll Hash1 = (HashR[l][0] - HashR[r+1][0] * Pow[r-l+1][0] % Mod[0]);
    Hash1 = (Hash1 + Mod[0]) % Mod[0];
    ll Hash2 = (HashR[l][1] - HashR[r+1][1] * Pow[r-l+1][1] % Mod[1]);
    Hash2 = (Hash2 + Mod[1]) % Mod[1];
    return (Hash1 << 31) | Hash2;
}
ll __get_hash(string &st)
{
    ll Hash1 = 0, Hash2 = 0;
    int l = st.size();
    for (int i = 1; i<=l; i++){
        Hash1 = (Hash1 * Base[0] + st[i-1]) % Mod[0], Hash1 %= Mod[0];
        Hash2 = (Hash2 * Base[1] + st[i-1]) % Mod[1], Hash2 %= Mod[1];
    }
    return (Hash1 << 31) | Hash2;
}
void gen_power()
{
    Pow[0][0] = Pow[0][1] = 1;
    for (int i = 1; i<nax; i++){
        Pow[i][0] = Pow[i-1][0] * Base[0] % Mod[0];
        Pow[i][1] = Pow[i-1][1] * Base[1] % Mod[1];
    }
}

int main ()
{
    #ifdef Lollipop
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    #endif
    
    gen_power();
    
    cin >> S;
    build_hash();

    return 0;
}
