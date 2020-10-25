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

const int nax = 2e5 + 10;
#define left (node * 2)
#define right (node * 2 + 1)
ll lazy[nax * 4];
ll tree[nax * 4];
int n;

void build(int node = 1, int l = 0, int r = n - 1)
{
    if (l == r){
        tree[node] = ara[l];
        return;
    }
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[node] = tree[left] + tree[right];
}

void update(int node, int l, int r, ll x)
{
    lazy[node] += x;
    tree[node] += (r - l + 1) * x;
}

void shift(int node, int l, int r)
{
    int mid = (l + r) / 2;
    update(left, l, mid, lazy[node]);
    update(right, mid + 1, r, lazy[node]);
    lazy[node] = 0;
}

void increase (int x, int y, ll v, int node = 1, int l = 0, int r = n - 1)
{
    if (l > y || r < x){
        return;
    }
    if (l >= x && r <= y){
        update(node, l, r, v);
        return;
    }
    shift(node, l, r);
    int mid = (l + r) / 2;
    increase(x, y, v, left, l, mid);
    increase(x, y, v, right, mid + 1, r);
    tree[node] = tree[left] + tree[right];
}

ll sum(int x, int y, int node = 1, int l = 0, int r = n - 1)
{
    if (l > y || r < x){
        return 0;
    }
    if (l >= x && r <= y){
        return tree[node];
    }
    shift(node, l, r);
    int mid = (l + r) / 2;
    return sum(x, y, left, l, mid) + sum(x, y, right, mid + 1, r);
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
    for (int cs = 1; cs <= t; cs++){
        mem(tree, 0);
        mem(lazy, 0);
        int q;
        scanf ("%d %d", &n, &q);
        printf ("Case %d:\n", cs);
        while (q--){
            int type;
            scanf ("%d", &type);
            if (type == 0){
                int p, q;
                ll v;
                scanf ("%d %d %lld",&p, &q, &v);
                increase(p, q, v);
            }
            else{
                int p, q;
                scanf ("%d %d", &p, &q);
                printf ("%lld\n", sum(p, q));
            }
        }
    }
    return 0;
}


