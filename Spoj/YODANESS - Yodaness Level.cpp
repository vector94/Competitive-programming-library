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

const int nax = 3e4 + 5;
map<string, int> MP;
#define mid ((l + r) / 2)
#define left (node * 2)
#define right (node * 2 + 1)
int ara[nax], tree[4 * nax];
int n;

void update(int x, int node = 1, int l = 1, int r = n)
{
    if (l > x || r < x){
        return;
    }
    if (l == x && r == x){
        tree[node] = 1;
        return;
    }
    update(x, left, l, mid);
    update(x, right, mid + 1, r);
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
    return query(x, y, left, l, mid) + query(x, y, right, mid + 1, r);
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            string s;
            cin >> s;
            MP[s] = i;
        }
        for (int i = 1; i <= n; i++){
            string s;
            cin >> s;
            ara[i] = MP[s];
        }
        int res = 0;
        for (int i = 1; i <= n; i++){
            res += query(ara[i], n);
            update(ara[i]);
        }
        cout << res << endl;
        MP.clear();
        mem(tree, 0);
    }
    return 0;
}

