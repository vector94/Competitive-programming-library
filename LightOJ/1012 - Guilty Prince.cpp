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

int ans;
int n, m;
char grid[30][30];
bool check[30][30];

void dfs(int x, int y)
{
    ans++;
    if (grid[x+1][y] == '.' && x+1 < n && check[x+1][y] == 0){
        check[x+1][y] = 1;
        dfs(x+1, y);
    }
    if (grid[x][y+1] == '.' && y+1 < m && check[x][y+1] == 0){
        check[x][y+1] = 1;
        dfs(x, y+1);
    }
    if (grid[x-1][y] == '.' && x-1 > -1 && check[x-1][y] == 0){
        check[x-1][y] = 1;
        dfs(x-1, y);
    }
    if (grid[x][y-1] == '.' && y-1 > -1 && check[x][y-1] == 0){
        check[x][y-1] = 1;
        dfs(x, y-1);
    }
}

int main ()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for (int cs = 1; cs<=t; cs++){
        cin >> m >> n;
        int p, q;
        ans = 0;
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                cin >> grid[i][j];
                check[i][j] = 0;
                if (grid[i][j] == '@'){
                    p = i;
                    q = j;
                }
            }
        }
        dfs(p, q);
        printf ("Case %d: %d\n", cs, ans);
    }
    return 0;
}
