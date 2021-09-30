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
        double R1, R2, R3;
        cin >> R1 >> R2 >> R3;
        
        double a = R1 + R2;
        double b = R2 + R3;
        double c = R1 + R3;
        
        double s = (a+b+c)/2;
        double area = sqrt(s*(s-a)*(s-b)*(s-c));
        
        double angle1 = acos((a*a + c*c - b*b)/(2*a*c));
        double angle2 = acos((a*a + b*b - c*c)/(2*a*b));
        double angle3 = acos((b*b + c*c - a*a)/(2*b*c));
        
        double sector1 = (angle1*R1*R1)/2;
        double sector2 = (angle2*R2*R2)/2;
        double sector3 = (angle3*R3*R3)/2;
        
        double ans = area - (sector1 + sector2 + sector3);
        printf ("Case %d: %f\n", cs, ans);
    }
    return 0;
}

