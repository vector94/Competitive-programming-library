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

bool parity(int num)
{
    int cnt = 0;
    while (num){
        if (num%2 == 1){
            cnt++;
        }
        num/=2;
    }
    if (cnt % 2 == 0){
        return true;
    }
    return false;
}

int main ()
{
    #ifdef Lollipop
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        int n;
        cin >> n;
        bool ans = parity(n);
        if (ans){
            printf ("Case %d: even\n", cs);
        }
        else{
            printf ("Case %d: odd\n", cs);
        }
    }
    
    return 0;
}
