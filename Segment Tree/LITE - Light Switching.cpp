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
#define mid (l + r) / 2
#define left (node * 2)
#define right (node * 2 + 1)
int tree[4 * nax], lazy[4 * nax];
int n;

void pushdown(int node, int l, int r)
{
    if (lazy[node] == 0){
        return;
    }
    tree[left] = (mid - l + 1) - tree[left];
    tree[right] = (r - mid) - tree[right];
    lazy[left] ^= 1;
    lazy[right] ^= 1;
    lazy[node] = 0;
}

void update(int x, int y, int node = 1, int l = 1, int r = n)
{
    if (l > y || r < x){
        return;
    }
    if (l >= x && r <= y){
        tree[node] = (r - l + 1) - tree[node];
        lazy[node] ^= 1;
        return;
    }
    pushdown(node, l, r);
    update(x, y, left, l, mid);
    update(x, y, right, mid + 1, r);
    tree[node] = tree[left] + tree[right];
}

int query(int x, int y, int node = 1, int l = 1, int r = n)
{
    if (l > y || r < x){
        return 0;
    }
    if (l >= x && r <= y){
        return tree[node];
    }
    pushdown(node, l, r);
    return query(x, y, left, l, mid) + query(x, y, right, mid + 1, r);
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;
    int m;
    cin >> n >> m;
    while (m--){
        int type;
        cin >> type;
        if (type == 0){
            int x, y;
            cin >> x >> y;
            update(x, y);
        }
        else{
            int x, y;
            cin >> x >> y;
            cout << query(x, y) << endl;
        }
    }
    return 0;
}

