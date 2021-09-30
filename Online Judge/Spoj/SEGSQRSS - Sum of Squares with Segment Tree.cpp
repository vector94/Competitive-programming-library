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
#define SQ(x)                   ((x) * (x))
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
#define left (2 * node)
#define right (2 * node + 1)
struct data
{
    ll sum, sq_sum;
}tree[4 * nax];
ll ara[nax], lazy1[4 * nax], lazy2[4 * nax];
int n;

void build(int node = 1, int l = 1, int r = n)
{
    if (l == r){
        tree[node].sum = ara[l];
        tree[node].sq_sum = SQ(ara[l]);
        return;
    }
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].sq_sum = tree[left].sq_sum + tree[right].sq_sum;
}

void push_down1(int node, int l, int r)
{
    if (lazy1[node] == 0){
        return;
    }
    tree[left].sq_sum += tree[left].sum * (ll)(mid - l + 1) * lazy1[node] + SQ(lazy1[node]) * (ll)(mid - l + 1);
    tree[right].sq_sum += tree[right].sum * (ll)(r - mid) * lazy1[node] + SQ(lazy1[node]) * (ll)(r - mid);
    tree[left].sum += (ll)(mid - l + 1) * lazy1[node];
    tree[right].sum += (ll)(r - mid) * lazy1[node];
    lazy1[left] += lazy1[node];
    lazy1[right] += lazy1[node];
    lazy1[node] = 0;
}

void push_down2(int node, int l, int r)
{
    if (lazy2[node] == 0){
        return;
    }
    tree[left].sq_sum = SQ(lazy2[node]) * (ll)(mid - l + 1);
    tree[right].sq_sum = SQ(lazy2[node]) * (ll)(r - mid);
    tree[left].sum = (ll)(mid - l + 1) * lazy2[node];
    tree[right].sum = (ll)(r - mid) * lazy2[node];
    lazy2[left] = lazy2[node];
    lazy2[right] = lazy2[node];
    lazy2[node] = 0;
}

void update(int x, int y, ll v, int type, int node = 1, int l = 1, int r = n)
{
    if (l > y || r < x){
        return;
    }
    if (l >= x && r <= y){
        if (type == 0){
            tree[node].sq_sum += tree[node].sum * (ll)(r - l + 1) * v + SQ(v) * (ll)(r - l + 1);
            tree[node].sum += (ll)(r - l + 1) * v;
            lazy1[node] += v;
        }
        else{
            tree[node].sq_sum = SQ(v) * (ll)(r - l + 1);
            tree[node].sum = (ll)(r - l + 1) * v;
            lazy2[node] = v;
        }
        return;
    }
    push_down1(node, l, r);
    push_down2(node, l, r);
    update(x, y, v, type, left, l, mid);
    update(x, y, v, type, right, mid + 1, r);
    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].sq_sum = tree[left].sq_sum + tree[right].sq_sum;
}

ll query(int x, int y, int node = 1, int l = 1, int r = n)
{
    if (l > y || r < x){
        return 0;
    }
    if (l >= x && r <= y){
        return tree[node].sq_sum;
    }
    push_down1(node, l, r);
    push_down2(node, l, r);
    return query(x, y, left, l, mid) + query(x, y, right, mid + 1, r);
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        int q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++){
            cin >> ara[i];
        }
        mem(tree, 0);
        mem(lazy1, 0);
        mem(lazy2, 0);
        build();
        printf ("Case %d:\n", cs);
        while (q--){
            int type;
            cin >> type;
            if (type == 2){
                int x, y;
                cin >> x >> y;
                cout << query(x, y) << endl;
            }
            else if (type == 1){
                int x, y, v;
                cin >> x >> y >> v;
                update(x, y, v, 0);
            }
            else{
                int x, y, v;
                cin >> x >> y >> v;
                update(x, y, v, 1);
            }
        }
    }
    return 0;
}

