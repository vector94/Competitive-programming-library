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
    for (int cs = 1; cs <= t; cs++){
        int n, m;
        cin >> n >> m;
        vector<int> ara(n);
        for (int i = 0; i<n; i++){
            cin >> ara[i];
        }
        char op;
        int x;
        while (m--){
            cin >> op;
            if (op == 'S'){
                cin >> x;
                for (int i = 0; i<n; i++){
                    ara[i] += x;
                }
            }
            else if (op == 'M'){
                cin >> x;
                for (int i = 0; i<n; i++){
                    ara[i] *= x;
                }
                
            }
            else if (op == 'D'){
                cin >> x;
                for (int i = 0; i<n; i++){
                    ara[i] /= x;
                }
            }
            else if (op == 'R'){
                reverse(all(ara));
            }
            else if (op == 'P'){
                int p, q;
                cin >> p >> q;
                swap(ara[p], ara[q]);
            }
        }
        printf ("Case %d:\n", cs);
        for (int i = 0; i<n; i++){
            cout << ara[i];
            if (i != n-1){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

