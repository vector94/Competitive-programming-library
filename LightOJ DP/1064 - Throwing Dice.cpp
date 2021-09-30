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

ll p[30], dp[30][155];
int mark[30][155];
int cs, n, x;

void pre_cal()
{
    p[0] = 1;
    for (int i = 1; i <= 25; i++){
        p[i] = p[i - 1] * 6;
    }
}

ll solve(int turn, int total)
{
    if (turn == n){
        return (total >= x);
    }
    ll &ret = dp[turn][total];
    if (mark[turn][total] == cs)  return ret;
    mark[turn][total] = cs;
    ret = 0;
    for (int i = 1; i <= 6; i++){
        ret += solve(turn + 1, total + i);
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
    pre_cal();
    int t;
    cin >> t;
    for (cs = 1; cs <= t; cs++){
        cin >> n >> x;
        ll num = solve(0, 0);
        ll den = p[n];
        ll gcd = __gcd(num, den);
        num /= gcd;
        den /= gcd;
        printf ("Case %d: ", cs);
        if (den == 1){
            cout << num << endl;
        }
        else{
            cout << num << "/" << den << endl;
        }
    }
    return 0;
}

