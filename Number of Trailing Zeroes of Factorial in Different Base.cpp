#include <bits/stdc++.h>
#define ll                  long long int
#define fi                  first
#define se                  second
#define pb                  push_back
#define mp                  make_pair
using namespace std;

vector<pair<ll, ll> >primeFact; 

ll factorialPrimePower(ll n, ll p)
{
    ll freq = 0;
    while (n){
        freq += n/p;
        n/=p;
    }
    return freq;
}

int main ()
{
    #ifdef Lollipop
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    #endif
    ll n, b;
    cin >> n >> b;
    ll temp = b;
    for (ll i = 2; i*i <= temp; i++){
        if (temp%i == 0){
            int cnt = 0;
            while (temp%i == 0){
                temp/=i;
                cnt++;
            }
            primeFact.pb(mp(i, cnt));
        }
    }
    if (temp > 1){
        primeFact.pb(mp(temp, 1));
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i<primeFact.size(); i++){
        ll x = factorialPrimePower(n, primeFact[i].fi);
        x/=primeFact[i].se;
        ans = min(ans, x);
    }
    cout << ans << endl;
    return 0;
}

