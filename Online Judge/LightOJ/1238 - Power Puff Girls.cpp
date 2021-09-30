#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define pbb pop_back
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(x.begin(),x.end()),x.end())
#define mem(array, value) memset(array, value, sizeof(array))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a,b))*b
#define line cout << "\n==========\n"
#define mod 1000000007
#define SIZE 1000001

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int ans;
int row, column;
char grid[30][30];
bool visit[30][30];
int level[30][30];

void bfs(int x, int y)
{
    for (int i = 0; i<row; i++){
        for (int j = 0; j<column; j++){
            visit[i][j] = 0;
            level[i][j] = 0;
        }
    }
    queue<pair<int, int> > Q;
    Q.push(make_pair(x, y));
    while (!Q.empty()){
        x = Q.front().fi;
        y = Q.front().se;
        Q.pop();
        if (grid[x][y] == 'h'){
            ans = max(ans, level[x][y]);
            return;
        }
        for (int i = 0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx >= 0 && nx < row && ny >= 0 && ny < column
                && grid[nx][ny] != 'm' && grid[nx][ny] != '#' && !visit[nx][ny]){
                visit[nx][ny] = 1;
                level[nx][ny] = level[x][y]+1;
                Q.push(make_pair(nx, ny));
            }
        }
    }
}

int main ()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for (int cs = 1; cs<=t; cs++){
        int ax, ay;
        int bx, by;
        int cx, cy;
        cin >> row >> column;
        for (int i = 0; i<row; i++){
            for (int j = 0; j<column; j++){
                cin >> grid[i][j];
                if (grid[i][j] == 'a'){
                    ax = i;
                    ay = j;
                }
                else if (grid[i][j] == 'b'){
                    bx = i;
                    by = j;
                }
                else if (grid[i][j] == 'c'){
                    cx = i;
                    cy = j;
                }
            }
        }
        ans = 0;
        bfs(ax, ay);
        bfs(bx, by);
        bfs(cx, cy);
        printf ("Case %d: %d\n", cs, ans);
    }
    return 0;
}
