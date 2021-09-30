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
#define SIZE 1000009

struct data
{
    int x, y;
};

int node;
int ans;
char grid[15][15];
int level[15][15];
bool visit[15][15];
data cell[30];
bool check[30];

void bfs(int n)
{
    for (int i = 0; i<node; i++){
        for (int j = 0; j<node; j++){
            visit[i][j] = 0;
            level[i][j] = 0;
        }
    }
    char ch = n + 'A' + 1;
    queue<data> Q;
    data temp;
    temp.x = cell[n].x;
    temp.y = cell[n].y;
    Q.push(temp);

    while (!Q.empty()){
        temp = Q.front();
        Q.pop();
        int a = temp.x;
        int b = temp.y;
        if (grid[a][b] == ch){
            grid[cell[n].x][cell[n].y] = '.';
            ans += level[a][b];
            return;
        }
        if (a+1 < node && !visit[a+1][b] && (grid[a+1][b] == '.' || grid[a+1][b] == ch)) {
            visit[a+1][b] = 1;
            level[a+1][b] = level[a][b]+1;
            temp.x = a+1;
            temp.y = b;
            Q.push(temp);
        }
        if (b+1 < node && !visit[a][b+1] && (grid[a][b+1] == '.' || grid[a][b+1] == ch)){
            visit[a][b+1] = 1;
            level[a][b+1] = level[a][b]+1;
            temp.x = a;
            temp.y = b+1;
            Q.push(temp);
        }
        if (a-1 >= 0 && !visit[a-1][b] && (grid[a-1][b] == '.' || grid[a-1][b] == ch)){
            visit[a-1][b] = 1;
            level[a-1][b] = level[a][b]+1;
            temp.x = a-1;
            temp.y = b;
            Q.push(temp);
        }
        if (b-1 >= 0 && !visit[a][b-1] && (grid[a][b-1] == '.' || grid[a][b-1] == ch)){
            visit[a][b-1] = 1;
            level[a][b-1] = level[a][b]+1;
            temp.x = a;
            temp.y = b-1;
            Q.push(temp);
        }
//        line;
//        cout << ch << endl;
//        for (int i = 0; i<node; i++){
//            for (int j = 0;j<node; j++){
//                cout << level[i][j];
//            }
//            cout << endl;
//        }
//        line;
    }
}

int main ()
{
    int t;
    cin >> t;
    for (int cs = 1; cs<=t; cs++){
        cin >> node;
        int food = 0;
        for (int i = 0; i<node; i++){
            for (int j = 0; j<node; j++){
                cin >> grid[i][j];
                if (isalpha(grid[i][j])){
                    data temp;
                    temp.x = i;
                    temp.y = j;
                    cell[grid[i][j] - 'A'] = temp;
                    food++;
                }
            }
        }
        ans = 0;
        for (int i = 0; i<food-1; i++){
            bfs(i);
        }
        grid[cell[food-1].x][cell[food-1].y] = '.';
        for (int i = 0; i<node; i++){
            for (int j = 0; j<node; j++){
                if (isalpha(grid[i][j])){
                    ans = -1;
                }
            }
        }
        if (ans == -1){
            printf ("Case %d: Impossible\n", cs);
        }
        else {
            printf ("Case %d: %d\n", cs, ans);
        }
    }
    return 0;
}
