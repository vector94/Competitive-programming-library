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

map<string, int> M;
void preCal()
{
    M["January"] = 1;
    M["February"] = 2;
    M["March"] = 3;
    M["April"] = 4;
    M["May"] = 5;
    M["June"] = 6;
    M["July"] = 7;
    M["August"] = 8;
    M["September"] = 9;
    M["October"] = 10;
    M["November"] = 11;
    M["December"] = 12;
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
        string month1, month2;
        char comma;
        int day1, year1, day2, year2;
        cin >> month1 >> day1 >> comma >> year1;
        cin >> month2 >> day2 >> comma >> year2;
        
        int m1 = M[month1];
        int m2 = M[month2];
        
        year1--;
        if (m1 > 2){
            year1++;
        }
        if (m2 == 1 || (m2 == 2 && day2 < 29)){
            year2--;
        }
        
        int ans = (year2/4 - year2/100 + year2/400) - (year1/4 - year1/100 + year1/400);
        printf ("Case %d: %d\n", cs, ans);
    }
    return 0;
}
