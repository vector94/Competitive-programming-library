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

const int nax = 1e5 + 5;
ll arr[nax];
int n;
ll solve()
{
    if (n == 1){
        return arr[0];
    }
    ll prev_max, prev_min, max_product;
    max_product = prev_max = prev_min = arr[0];

    for (int i = 1; i < n; i++){
        ll cur_max = max(prev_max * arr[i], max(prev_min * arr[i], arr[i]));
        ll cur_min = min(prev_max * arr[i], min(prev_min * arr[i], arr[i]));
        max_product = max(max_product, cur_max);
        prev_max = cur_max;
        prev_min = cur_min;
    }
    return max_product;
}
int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll res = solve();
    cout << res << endl;
    return 0;
}


