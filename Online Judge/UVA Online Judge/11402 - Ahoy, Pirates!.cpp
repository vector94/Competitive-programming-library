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

const int nax = 1024007;
#define mid ((l + r) / 2)
#define left (node * 2)
#define right (node * 2 + 1)
int ara[nax], tree[4 * nax], lazy[4 * nax];
int n;

void build(int node = 1, int l = 0, int r = n - 1)
{
    if (l == r){
        tree[node] = ara[l];
        return;
    }
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[node] = tree[left] + tree[right];
}

int invert(int type)
{
    if (type == 0)  return 3;
    if (type == 1)  return 2;
    if (type == 2)  return 1;
    if (type == 3)  return 0;
}

void pushdown(int node, int l, int r)
{
    if (lazy[node] == 0){
        return;
    }
    if (lazy[node] == 1){
        tree[left] = mid - l + 1;
        tree[right] = r - mid;
        lazy[left] = lazy[node];
        lazy[right] = lazy[node];
    }
    else if (lazy[node] == 2){
        tree[left] = 0;
        tree[right] = 0;
        lazy[left] = lazy[node];
        lazy[right] = lazy[node];
    }
    else{
        tree[left] = (mid - l + 1) - tree[left];
        tree[right] = (r - mid) - tree[right];
        lazy[left] = invert(lazy[left]);
        lazy[right] = invert(lazy[right]);
    }
    lazy[node] = 0;
}

void update(int x, int y, int type, int node = 1, int l = 0, int r = n - 1)
{
    if (l > y || r < x){
        return;
    }
    if (l >= x && r <= y){
        if (type == 1){
            tree[node] = r - l + 1;
            lazy[node] = 1;
        }
        else if (type == 2){
            tree[node] = 0;
            lazy[node] = 2;
        }
        else{
            tree[node] = (r - l + 1) - tree[node];
            lazy[node] = invert(lazy[node]);
        }
        return;
    }
    pushdown(node, l, r);
    update(x, y, type, left, l, mid);
    update(x, y, type, right, mid + 1, r);
    tree[node] = tree[left] + tree[right];
}

int query(int x, int y, int node = 1, int l = 0, int r = n - 1)
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
    //fastRead;
    int t;
    scanf ("%d", &t);
    for (int cs = 1; cs <= t; cs++){
        int idx = 0;
        n = 0;
        int m;
        scanf ("%d", &m);
        mem(ara, 0);
        while (m--){
            int T;
            scanf ("%d", &T);
            string s;
            cin >> s;
            int len = (int)s.size();
            while (T--){
                n += len;
                for (int i = 0; i < len; i++){
                    ara[idx++] = s[i] - '0';
                }
            }
        }
        mem(tree, 0);
        mem(lazy, 0);
        build();
        int q;
        scanf ("%d", &q);
        int Q = 0;
        printf ("Case %d:\n", cs);
        while (q--){
            char type;
            getchar();
            scanf ("%c", &type);
            int x, y;
            scanf ("%d %d", &x, &y);
            if (type == 'F'){
                update(x, y, 1);
            }
            else if (type == 'E'){
                update(x, y, 2);
            }
            else if (type == 'I'){
                update(x, y, 3);
            }
            else if (type == 'S'){
                printf ("%Q%d: %d\n", ++Q, query(x, y));
            }
        }
    }
    return 0;
}

