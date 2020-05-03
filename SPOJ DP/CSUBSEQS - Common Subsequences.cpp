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

int nxt[4][55][26];
ll dp[55][55][55][55];
string s[4];
int cs;
int len1, len2, len3, len4;

ll solve(int i, int j, int k, int l)
{
    if (i == len1 || j == len2 || k == len3 || l == len4){
        return 1;
    }
    ll &ret = dp[i][j][k][l];
    if (ret != -1){
        return ret;
    }
    ret = 1;
    for (int x = 0; x < 26; x++){
        if (nxt[0][i][x] < len1 && nxt[1][j][x] < len2 && nxt[2][k][x] < len3 && nxt[3][l][x] < len4){
            ret += solve(nxt[0][i][x] + 1, nxt[1][j][x] + 1, nxt[2][k][x] + 1, nxt[3][l][x] + 1);
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
    fastRead;
    for (int i = 0; i < 4; i++){
        cin >> s[i];
    }
    mem(dp, -1);
    len1 = s[0].size();
    len2 = s[1].size();
    len3 = s[2].size();
    len4 = s[3].size();
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 4; j++){
            int pre = s[j].size();
            for (int k = s[j].size() - 1; k >= 0; k--){
                if (s[j][k] - 'a' == i){
                    pre = k;
                }
                nxt[j][k][i] = pre;
            }
        }
    }
    cout << solve(0, 0, 0, 0) - 1 << endl;
    return 0;
}

