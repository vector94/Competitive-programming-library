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
#define endl                    "\n"
#define fastRead 	            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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

const int nax = 1e5 + 5;
#define mid ((l + r) / 2)
#define left (node * 2)
#define right (node * 2 + 1)
const int INF = 1e9;
pii tree[4 * nax];
int ara[nax];
int n;

pii combine(pii a, pii b)
{
    if (a.fi > b.fi){
        return a;
    }
    if (b.fi > a.fi){
        return b;
    }
    return mp(a.fi, a.se + b.se);
}

void build(int node = 1, int l = 1, int r = n)
{
    if (l == r){
        tree[node] = mp(ara[l], 1);
    }
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[node] = combine(tree[left], tree[right]);
}

pii get_max(int x, int y, int node = 1, int l = 1, int r = n)
{
    if (l > y || r < x){
        return pii(-INF, 0);
    }
    if (l >= x && r <= y){
        return tree[node];
    }
    return combine(get_max(x, y, left, l, mid), get_max(x, y, right, mid + 1, r));
}

void update(int x, int v, int node = 1, int l = 1, int r = n)
{
    if (l > x || r < x){
        return;
    }
    if (l == x && r == x){
        tree[node] = mp(v, 1);
        return;
    }
    update(x, v, left, l, mid);
    update(x, v, right, mid + 1, r);
    tree[node] = combine(tree[left], tree[right]);
}

int main ()
{
    #ifdef Lollipop
        //freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;

    return 0;
}

