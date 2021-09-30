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
#define left (node * 2)
#define right (node * 2 + 1)
int ara[nax], tree[4 * nax];
int n;

void build(int node = 1, int l = 0, int r = n - 1)
{
    if (l == r){
        tree[node] = ara[l];
        return;
    }
    int mid = (l + r) / 2;
    build (left, l, mid);
    build(right, mid + 1, r);
    tree[node] = min(tree[left], tree[right]);
}

int query(int x, int y, int node = 1, int l = 0, int r = n - 1)
{
    if (l > y || r < x){
        return 1e9;
    }
    if (l >= x && r <= y){
        return tree[node];
    }
    int mid = (l + r) / 2;
    return min(query(x, y, left, l, mid), query(x, y, right, mid + 1, r));
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
        for (int i = 0; i < n; i++){
            cin >> ara[i];
        }
        mem(tree, 0);
        build();
        printf ("Scenario #%d:\n", cs);
        while (q--){
            int l, r;
            cin >> l >> r;
            cout << query(l - 1, r - 1) << endl;
        }
    }
    return 0;
}

