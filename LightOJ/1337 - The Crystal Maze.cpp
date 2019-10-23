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
#define PI      	        acos(-1.0)
#define INF     	        1e9
#define EPS     	        1e-8
#define line                cout << "\n==========\n"
#define fastRead 	        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedSet; 

int dx[] = {1, -1, 0, 0},                  dy[] = {0, 0, 1, -1};                  // 4 Direction
//int dx[] = {1, -1, 0, 0, 1, 1, -1, -1},    dy[] = {0, 0, 1, -1, 1, -1, 1, -1};    // 8 Direction
//int dx[] = {1, -1, 1, -1, 2, 2, -2, -2},   dy[] = {2, 2, -2, -2, 1, -1, 1, -1};   // Knight Direction

const int maxn = 509;
char grid[maxn][maxn];
int visit[maxn][maxn];
int level[maxn][maxn];
int row, column;

void Clear()
{
    for (int i = 1; i<=row; i++){
        for (int j = 1; j<=column; j++){
            visit[i][j] = 0;
            level[i][j] = 0;
        }
    }
}

bool valid (int x, int y)
{
    return (x >= 1 && y >= 1 && x <= row && y <= column && grid[x][y] != '#');
}

int bfs(int x, int y)
{
    int cnt = 0;
    queue<pii> Q;
    visit[x][y] = 1;
    Q.push(mp(x, y));
    int ax, ay;
    while (!Q.empty()){
        x = Q.front().fi;
        y = Q.front().se;
        Q.pop();
        if (grid[x][y] == 'C'){
            cnt++;
        }
        for (int i = 0; i<4; i++){
            ax = x+dx[i];
            ay = y+dy[i];
            if (valid(ax, ay) && visit[ax][ay] == 0){
                visit[ax][ay] = 1;
                Q.push(mp(ax, ay));
            }
        }
    }
    return cnt;
}

void bfsUtil(int x, int y, int cnt)
{
    queue<pii> Q;
    Q.push(mp(x, y));
    level[x][y] = cnt;
    visit[x][y] = 2;
    int ax, ay;
    while(!Q.empty()){
        x = Q.front().fi;
        y = Q.front().se;
        Q.pop();
        for (int i = 0; i<4; i++){
            ax = x + dx[i];
            ay = y + dy[i];
            if (valid(ax, ay) && visit[ax][ay] == 1){
                level[ax][ay] = cnt;
                visit[ax][ay] = 2;
                Q.push(mp(ax, ay));
            }
        }
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
        printf ("Case %d:\n", cs);
        int q;
        cin >> row >> column >> q;
        for (int i = 1; i<=row; i++){
            for (int j = 1; j<=column; j++){
                cin >> grid[i][j];
            }
        }
        Clear();
        int x, y;
        while (q--){
            cin >> x >> y;
            if (grid[x][y] == '#'){
                cout << 0 << endl;
            }
            else if (visit[x][y] == 0){
                int ans = bfs(x, y);
                bfsUtil(x, y, ans);
                cout << ans << endl;
            }
            else {
                cout << level[x][y] << endl;
            }
        }
    }
    return 0;
}

