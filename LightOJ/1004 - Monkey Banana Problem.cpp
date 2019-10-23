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

int matrix[200][100];
int dp[200][100];
int n;

bool valid (int i, int j)
{
    return i >= 0 && j >= 0 && i < 2*n-1 && j < n && matrix[i][j] != -1;
}

int call(int i, int j)
{
    if (valid(i, j)){
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        int ret = 0;
        ret = max(ret, call(i+1, j) + matrix[i][j]);
        if (i < n-1){
            ret = max(ret, call(i+1, j+1) + matrix[i][j]);
        }
        else{
            ret = max(ret, call(i+1, j-1) + matrix[i][j]);
        }
        return dp[i][j] = ret;
    }
    else{
        return 0;
    }
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
        mem(matrix, -1);
        mem(dp, -1);
        cin >> n;
        for (int i = 0; i<2*n-1; i++){
            if (i < n){
                for (int j = 0; j<=i; j++){
                    cin >> matrix[i][j];
                }
            }
            else {
                for (int j = 0; j < 2*n-i-1; j++){
                    cin >> matrix[i][j];
                }
            }
        }
        printf ("Case %d: %d\n", cs, call(0, 0));
    }
    
    return 0;
}

