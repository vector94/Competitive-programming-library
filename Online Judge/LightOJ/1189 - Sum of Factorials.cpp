#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
#define ll                  long long int
#define ull                 unsigned long long int
#define ld                  long double
#define fi                  first
#define se                  second
#define pb                  push_back
#define pbb                 pop_back
#define mp                  make_pair
#define pii     	        pair<int,int>
#define all(x)              x.begin(), x.end()
#define uniq(x)             x.erase(unique(x.begin(),x.end()),x.end())
#define mem(array, value)   memset(array, value, sizeof(array))
#define lcm(a,b)            (abs(a)/gcd(a,b))*abs(b)
#define PI      	        2*acos(0.0)
#define INF     	        1e9
#define EPS     	        1e-8
#define line                cout << "\n==========\n"
#define fastRead 	        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedSet; 

const ll maxn = 1e18;
ll fac[20];
vector<int> ans;

void preCal()
{
    fac[0] = 1;
    for (int i = 1; i<20; i++){
        fac[i] = fac[i-1] * i;
    }
}

void solve(ll n)
{
    for (int i = 19; i >= 0; i--){
        if (n >= fac[i]){
            n -= fac[i];
            ans.pb(i);
        }
    }
    if (n != 0){
        cout << "impossible";
    }
    else{
        for (int i = ans.size()-1; i >= 0; i--){
            cout << ans[i] << "!";
            if (i != 0){
                cout << "+";
            }
        }
    }
    ans.clear();
}

int main ()
{
    #ifdef Lollipop
    freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    #endif
    preCal();
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        ll n;
        cin >> n;
        printf ("Case %d: ", cs);
        solve(n);
        cout << endl;
    }
    return 0;
}
