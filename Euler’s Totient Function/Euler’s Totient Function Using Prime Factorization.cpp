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

vector<ll> prime_factor;
void prime_factorization(ll num)
{
    ll sqrtN = sqrt(num);
    for (ll i = 2; i <= sqrtN; i++){
        if (num % i == 0){
            while (num % i == 0){
                num /= i;
            }
            prime_factor.pb(i);
            sqrtN = sqrt(num);
        }
    }
    if (num > 1){
        prime_factor.pb(num);
    }
    sort(all(prime_factor));
}

ll eulier_phi(ll num)
{
    ll cnt = 0;
    for (int i = 0; i < prime_factor.size(); i++){
        ll x = (num / prime_factor[i]) - (cnt / prime_factor[i]);
        cnt += x;
    }
    return (num - cnt);
}

int main ()
{
    #ifdef Lollipop
        //freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    ll n;
    cin >> n;
    prime_factorization(n);
    cout << eulier_phi(n) << endl;
    return 0;
}


