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

const int maxn = 1000;
int nod[maxn+1];
int num[maxn];

bool cmp(int x, int y)
{
    if (nod[x] == nod[y]){
        return x > y;
    }
    else{
        return nod[x] < nod[y];
    }
}

void preCal ()
{
    for (int i = 1; i<=1000; i++){
        for (int j = i; j<=1000; j+=i){
            nod[j]++;
        }
    }
    for (int i = 0; i<maxn; i++){
        num[i] = i+1;
    }
    sort(num, num+maxn, cmp);
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
        int n;
        cin >> n;
        printf ("Case %d: %d\n", cs, num[n-1]);
    }
    return 0;
}

