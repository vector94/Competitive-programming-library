#include <bits/stdc++.h>
using namespace std;
#define ll                  long long int

const int NAX = 1e5+5;
const int Mod[2] = {1000000007, 1000000009};
const int Base[2] = {31, 37};
ll Pow[NAX][2];
string S;
int Len;
ll HashF[NAX][2], HashR[NAX][2];

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
ll get_hash(int l, int r)
{
    l++, r++;
    if (l == 1) return (HashF[r][0] << 31) | HashF[r][1];
    ll Hash1 = (HashF[r][0] - HashF[l-1][0] * Pow[r-l+1][0] % Mod[0]);
    Hash1 = (Hash1 + Mod[0]) % Mod[0];
    ll Hash2 = (HashF[r][1] - HashF[l-1][1] * Pow[r-l+1][1] % Mod[1]);
    Hash2 = (Hash2 + Mod[1]) % Mod[1];
    return (Hash1 << 31) | Hash2;
}
ll get_hash2(int l, int len)
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
    for (int i = 1; i<NAX; i++){
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
