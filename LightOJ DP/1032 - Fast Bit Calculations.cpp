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

int cs, sz;
vector<int> bits;
ll dp[2][2][35][35];
int mark[2][2][35][35];

ll cal(int is_small, int pre, int pos, int value)
{
    if (pos == sz){
        return value;
    }
    ll &ret = dp[is_small][pre][pos][value];
    int &m = mark[is_small][pre][pos][value];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 0;
    int limit = is_small ? 1 : bits[pos];
    for (int i = 0; i <= limit; i++){
        ret += cal(is_small | (i < bits[pos]), i, pos + 1, value + (pre == 1 && i == 1));
    }
    return ret;
}

ll solve(int num)
{
    bits.clear();
    while (num){
        bits.pb(num % 2);
        num /= 2;
    }
    sz = bits.size();
    reverse(all(bits));
    return cal(0, 0, 0, 0);
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    scanf ("%d", &t);
    for (cs = 1; cs <= t; cs++){
        int n;
        cin >> n;
        printf ("Case %d: %lld\n", cs, solve(n));
    }
    return 0;
}

