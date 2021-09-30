#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii     	            pair<int,int>
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define fastRead 	            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define bitcount(number)        __builtin_popcount(number)
#ifdef Lollipop
    #define line                    cout << "\n===================\n"
    #define trace(...)              __f( #__VA_ARGS__ , __VA_ARGS__ )
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " = " << arg1 << "\n";
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " = " << arg1 << " , ";
    __f(comma + 1, args...);
    }
#else
    #define line
    #define trace(...)
#endif

ll Set(ll num, int pos){
    return num | (1LL << pos);
}
bool Check(ll num, int pos){
    return (bool)(num & (1LL << pos));
}

int n, cs;
struct point
{
    int x, y;
}a[20];
int lines[20][20];
int dp[1 << 16], mark[1 << 16];

bool collinear(point p, point q, point r)
{
    return ((q.x - p.x) * (r.y - q.y) == (r.x - q.x) * (q.y - p.y));
}

int solve(int mask)
{
    if (bitcount(mask) >= n - 1){
        return n - bitcount(mask);
    }
    int &ret = dp[mask];
    int &m = mark[mask];
    if (m == cs){
        return ret;
    }
    m = cs;
    ret = 1e5;
    for (int i = 0; i < n; i++){
        if (!Check(mask, i)){
            for (int j = i + 1; j < n; j++){
                if (Check(mask, j)){
                    continue;
                }
                int cur_mask = mask | lines[i][j];
                ret = min(ret, 1 + solve(cur_mask));
            }
            break;
        }
    }
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    scanf ("%d", &t);
    for (cs = 1; cs <= t; cs++){
        scanf ("%d", &n);
        for (int i = 0; i < n; i++){
            scanf ("%d %d", &a[i].x, &a[i].y);
        }
        mem(lines, 0);
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                for (int k = 0; k < n; k++){
                    if (collinear(a[i], a[j], a[k])){
                        lines[i][j] = Set(lines[i][j], k);
                    }
                }
            }
        }
        printf ("Case %d: %d\n", cs, solve(0));
    }
    return 0;
}

