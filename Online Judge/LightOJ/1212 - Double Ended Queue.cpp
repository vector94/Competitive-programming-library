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

deque<int> Q;

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
        string c;
        int x;
        printf ("Case %d:\n", cs);
        while (m--){
            cin >> c;
            if (c == "pushLeft" || c == "pushRight"){
                cin >> x;
                if (Q.size() == n){
                    cout << "The queue is full\n";
                }
                else{
                    if (c == "pushLeft"){
                        Q.pb(x);
                        printf ("Pushed in left: %d\n", x);
                    }
                    else{
                        Q.push_front(x);
                        printf ("Pushed in right: %d\n", x);
                    }
                }
            }
            else{
                if (!Q.size()){
                    cout << "The queue is empty\n";
                }
                else{
                    if (c == "popLeft"){
                        printf ("Popped from left: %d\n", Q.back());
                        Q.pbb();
                    }
                    else{
                        printf ("Popped from right: %d\n", Q.front());
                        Q.pop_front();
                    }
                }
            }
        }
        Q.clear();
    }
    return 0;
}
