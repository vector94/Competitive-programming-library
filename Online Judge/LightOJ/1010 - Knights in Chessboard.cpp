#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define pbb pop_back
#define make_pair mp
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(x.begin(),x.end()),x.end())
#define mem(array, value) memset(array, value, sizeof(array))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a,b))*b
#define line cout << "\n==========\n"
#define mod 1000000007
#define SIZE 1000001

int main ()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for (int cs = 1; cs<=t; cs++){
        int m, n;
        cin >> m >> n;
        int ans;
        if (min(m, n) == 1){
            ans = max(m, n);
        }
        else if (min(m, n) == 2){
            int x = max(m, n);
            if (x%4 == 1 || x%4 == 3){
                ans = x+1;
            }
            else {
                ans = x+(x%4);
            }
        }
        else if (n%2 == 0 && m%2 == 0){
            ans = n*(m/2);
        }
        else if (n%2 == 0 && m%2!= 0){
            ans = m*(n/2);
        }
        else if (n%2 != 0 && m%2 == 0){
            ans = n*(m/2);
        }
        else{
            if (n < m){
                swap(n, m);
            }
            int x = (n+1)/2;
            int y = (m+1)/2;
            ans = (x*y) + (x-1)*(m/2);
        }
        printf ("Case %d: %d\n", cs, ans);
    }
    return 0;
}
