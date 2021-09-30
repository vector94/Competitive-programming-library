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

const int N = 2e6;
bool prime[N + 5];
void sieve()
{
    prime[0] = prime[1] = true;
    for (int i = 4; i <= N; i += 2){
        prime[i] = true;
    }
    int sqrtN = sqrt(N);
    for (int i = 3; i <= sqrtN; i += 2){
        if (!prime[i]){
            for (int j = i * i; j <= N; j += 2 * i){
                prime[j] = true;
            }
        }
    }
}

#define mid ((l + r) / 2)
#define left (node * 2)
#define right (node * 2 + 1)
const int nax = 1e4 + 5;
int ara[nax], tree[4 * nax], lazy[4 * nax];
int n;

void build(int node = 1, int l = 1, int r = n)
{
    if (l == r){
        tree[node] = !prime[ara[l]];
        return;
    }
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[node] = tree[left] + tree[right];
}


void pushdown(int node, int l, int r)
{
    if (lazy[node] == 0){
        return;
    }
    tree[left] = !prime[lazy[node]] ? (mid - l + 1) : 0;
    tree[right] = !prime[lazy[node]] ? (r - mid) : 0;
    lazy[left] = lazy[right] = lazy[node];
    lazy[node] = 0;
}

void update(int x, int y, int v, int node = 1, int l = 1, int r = n)
{
    if (l > y || r < x){
        return;
    }
    if (l >= x && r <= y){
        tree[node] = !prime[v] ? (r - l + 1) : 0;
        lazy[node] = v;
        return;
    }
    pushdown(node, l, r);
    update(x, y, v, left, l, mid);
    update(x, y, v, right, mid + 1, r);
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
    //fastRead;
    sieve();
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        int q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++){
            cin >> ara[i];
        }
        mem(tree, 0);
        mem(lazy, 0);
        build();
        printf ("Case %d:\n", cs);
        while (q--){
            int type;
            cin >> type;
            if (type == 0){
                int x, y, v;
                cin >> x >> y >> v;
                update(x, y, v);
            }
            else{
                int x, y;
                cin >> x >> y;
                cout << query(x, y) << endl;
            }
        }
    }
    return 0;
}

