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
        cerr.write(names, comma - names) << " = " << arg1 << " , ";
    __f(comma + 1, args...);
    }
#else
    #define line
    #define trace(...)
#endif

string a, b;
int len1, len2;
int dp1[35][35], mark1[35][35];
int cs;

int solve1(int i, int j)
{
    if (i == len1 || j == len2){
        return 0;
    }
    int &ret = dp1[i][j];
    int &m = mark1[i][j];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 0;
    if (a[i] == b[j]){
        ret = 1 + solve1(i + 1, j + 1);
    }
    else{
        ret = max(solve1(i + 1, j), solve1(i, j + 1));
    }
    return ret;
}

ll dp2[35][35][35];
int mark2[35][35][35];

ll solve2(int len, int i, int j)
{
    if (i == len1 || j == len2){
        return (len == 0);
    }
    ll &ret = dp2[len][i][j];
    int &m = mark2[len][i][j];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 0;
    if (a[i] == b[j]){
        ret += solve2(len - 1, i + 1, j + 1);
    }
    else{
        ret = solve2(len, i + 1, j) + solve2(len, i, j + 1);
    }
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    cin >> t;
    for(cs = 1; cs <= t; cs++){
        cin >> a >> b;
        len1 = a.size();
        len2 = b.size();
        int lcs = solve1(0, 0);
        printf ("Case %d: %d %lld\n", cs, len1 + len2 - lcs, solve2(lcs, 0, 0));
    }
    return 0;
}

