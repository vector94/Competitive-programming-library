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

string binary(ll n)
{
    string ans;
    while (n){
        if (n%2 == 0){
            n/=2;
            ans.pb('0');
        }
        else{
            ans.pb('1');
            n/=2;
        }
    }
    ans.pb('0');
    reverse(all(ans));
    return ans;
}
ll decimal(string s)
{
    ll num = 0, p = 1;
    for (int i = s.size()-1; i>=0; i--){
        num += (s[i] - 48) * p;
        p*=2;
    }
    return num;
}

int main ()
{
    #ifdef Lollipop
    freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        ll n;
        cin >> n;
        string s =  binary(n);
        next_permutation(all(s));
        ll ans = decimal(s);
        printf ("Case %d: %lld\n", cs, ans);
    }
    return 0;
}

