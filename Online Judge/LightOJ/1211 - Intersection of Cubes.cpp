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

const int maxn = 1009;

int main ()
{
    #ifdef Lollipop
    freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        int xLow, yLow, zLow, xHigh, yHigh, zHigh;
        xLow = yLow = zLow = 0;
        xHigh = yHigh = zHigh = maxn;
        int n;
        int x1, y1, z1, x2, y2, z2;
        cin >> n;
        for (int i = 0; i<n; i++){
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            xLow = max(xLow, x1);
            yLow = max(yLow, y1);
            zLow = max(zLow, z1);
            xHigh = min(xHigh, x2);
            yHigh = min(yHigh, y2);
            zHigh = min(zHigh, z2);
        }
        int volume = (xHigh - xLow) * (yHigh - yLow) * (zHigh - zLow);
        printf ("Case %d: %d\n", cs, volume < 0 ? 0 : volume);
    }
    return 0;
}
