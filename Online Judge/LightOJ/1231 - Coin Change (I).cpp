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

const int mod = 1e8+7;
int coin[60], c[60];
int dp[60][30][1009];
int n, k;

int call(int i, int taken, int amount)
{
    if (i >= n){
        if (amount == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if (dp[i][taken][amount] != -1){
        return dp[i][taken][amount];
    }
    ll ret1 = 0;
    ll ret2 = 0;
    if (amount - coin[i] >= 0 && taken < c[i]){
        ret1 = call(i, taken+1, amount-coin[i]);
    }
    ret2 = call(i+1, 0, amount);
    return dp[i][taken][amount] = (ret1+ret2)%mod;
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
        mem(dp, -1);
        cin >> n >> k;
        for (int i = 0; i<n; i++){
            cin >> coin[i];
        }
        for (int i = 0; i<n; i++){
            cin >> c[i];
        }
        int ans = call(0, 0, k);
        printf ("Case %d: %d\n", cs, ans);
    }
    return 0;
}

