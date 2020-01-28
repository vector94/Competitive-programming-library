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
vector<int> input;
ll dp[2][2][20][20];
int mark[2][2][20][20];

ll cal(int is_start, int is_small, int pos, int cnt)
{
    if (pos >= sz){
        if (cnt <= 3 && cnt != 0){
            return 1;
        }
        return 0;
    }
    ll &ret = dp[is_start][is_small][pos][cnt];
    int &m = mark[is_start][is_small][pos][cnt];
    if (m == tc){
        return ret;
    }
    m = tc;
    int limit = is_small ? 9 : input[pos];
    ret = 0;
    if (is_start){
        for (int i = 1; i <= limit; i++){
            ret += cal(0, is_small | (i < input[pos]), pos + 1, cnt + (i != 0));
        }
        ret += cal(1, 1, pos + 1, 0);
    }
    else{
        for (int i = 0; i <= limit; i++){
            ret += cal(0, is_small | (i < input[pos]), pos + 1, cnt + (i != 0));
        }
    }
    return ret;
}

ll solve(ll num)
{
    if (num <= 9)   return num;
    input.clear();
    while (num){
        input.pb(num % 10);
        num /= 10;
    }
    reverse(all(input));
    tc++;
    sz = input.size();
    return cal(1, 0, 0, 0);
}

int main ()
{
    #ifdef Lollipop
        freopen ("in1.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        ll n, m;
        cin >> n >> m;
        cout << solve(m) - solve(n - 1) << endl;
    }
    return 0;
}

