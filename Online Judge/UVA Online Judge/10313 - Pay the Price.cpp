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

vector<int> v;
string s;
ll dp[305][305][305];

ll solve(int coin, int price, int cnt)
{
    if (price == 0 && cnt == 0){
        return 1;
    }
    if (coin < 1 || price < 1 || cnt < 1){
        return 0;
    }
    ll &ret = dp[coin][price][cnt];
    if (ret != -1){
        return ret;
    }
    ret = solve(coin - 1, price, cnt) + solve(coin, price - coin, cnt - 1);
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    mem(dp, -1);
    while (getline(cin, s)){
        stringstream str(s);
        int x;
        while (str >> x){
            v.pb(x);
        }
        ll res = 0;
        int sz = v.size();
        if (sz == 1){
            int n = v[0];
            for (int i = 1; i<= n; i++){
                res += solve(n, n, i);
            }
            if (n == 0) res = 1;
        }
        else if (sz == 2){
            int n = v[0];
            int l = v[1];
            l = min(l, n);
            for (int i = 1; i <= l; i++){
                res += solve(n, n, i);
            }
            if (n == 0) res = 1;
        }
        else{
            int n = v[0];
            int l = v[1];
            int r = v[2];
            if (l > n){
                res = 0;
            }
            else{
                r = min(r, n);
                for (int i = l; i <= r; i++){
                    res += solve(n, n, i);
                }
                if (n == 0) res = 1;
            }
        }
        cout << res << endl;
        v.clear();
    }
    return 0;
}
