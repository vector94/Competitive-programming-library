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

int tc, sz;
int a, b, k;
vector<int> input;
int dp[2][20][90][90];
int mark[2][20][90][90];

int cal(int is_small, int pos, int rem, int rem_digit)
{
    if (pos >= sz){
        if (rem + rem_digit == 0){
            return 1;
        }
        return 0;
    }
    int &ret = dp[is_small][pos][rem][rem_digit];
    int &m =  mark[is_small][pos][rem][rem_digit];
    if (m == tc){
        return ret;
    }
    ret = 0;
    m = tc;
    int limit = is_small ? 9 : input[pos];
    for (int i = 0; i <= limit; i++){
        ret += cal(is_small | (i < input[pos]), pos + 1, (rem * 10 + i) % k, (rem_digit + i) % k);
    }
    return ret;
}

int solve(int num)
{
    input.clear();
    while (num){
        input.pb(num % 10);
        num /= 10;
    }
    reverse(all(input));
    tc++;
    sz = input.size();
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
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        cin >> a >> b >> k;
        if (k > 81){
            printf ("Case %d: 0\n", cs);
            continue;
        }
        ll ans = solve(b) - solve(a - 1);
        printf ("Case %d: %d\n", cs, ans);
    }
    return 0;
}
