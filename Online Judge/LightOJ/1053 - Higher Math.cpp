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

int main ()
{
    #ifdef Lollipop
    freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;
    for (int cs = 1; cs<=t; cs++){
        int ara[3];
        for (int i = 0; i<3; i++){
            cin >> ara[i];
        }
        sort(ara, ara+3);
        printf ("Case %d: ", cs);
        if (ara[0] + ara[1] > ara[2]){
            if (ara[0]*ara[0] + ara[1]*ara[1] == ara[2]*ara[2]){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
        }
        else{
            cout << "no\n";
        }
    }
    return 0;
}

