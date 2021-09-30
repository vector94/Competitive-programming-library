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
const int mod = 1000000007;
#define mid ((l + r) / 2)
#define left (node * 2)
#define right (node * 2 + 1)
int ara[nax], temp[nax], tree[4 * nax];
int n;
map<int, int> MP;

ll query(int x, int y, int node = 1, int l = 1, int r = n)
{
    if (l > y || r < x){
        return 0;
    }
    if (l >= x && r <= y){
        return tree[node];
    }
    return (query(x, y, left, l, mid) + query(x, y, right, mid + 1, r)) % mod;
}

void update(int x, int v, int node = 1, int l = 1, int r = n)
{
    if (l > x || r < x){
        return;
    }
    if (l == x && r == x){
        tree[node] = v;
        return;
    }
    update(x, v, left, l, mid);
    update(x, v, right, mid + 1, r);
    tree[node] = (tree[left] + tree[right]) % mod;
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
        int m;
        scanf ("%d", &m);
        n = 0;
        mem(tree, 0);
        MP.clear();
        for (int i = 0; i < m; i++){
            scanf ("%d", &ara[i]);
            temp[i] = ara[i];
        }
        sort(temp, temp + m);
        for (int i = 0; i < m; i++){
            if (!MP[temp[i]]){
                MP[temp[i]] = ++n;
            }
        }
        for (int i = 0; i < m; i++){
            ll v = query(1, MP[ara[i]]) + 1;
            v %= mod;
            update(MP[ara[i]], v);
        }
        printf ("Case %d: %lld\n", cs, query(1, n));
    }
    return 0;
}

