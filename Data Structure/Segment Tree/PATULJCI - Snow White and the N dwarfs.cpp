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

const int nax = 3e5 + 5;
const int N = 1e5 + 5;
vector<int> idx[N];
#define mid ((l + r) / 2)
#define left (node * 2)
#define right (node * 2 + 1)
int ara[nax], tree[4 * nax];
int n, c;

int Merge(int l_res, int r_res, int l, int r)
{
    int len = r - l + 1;
    if (l_res != -1){
        int cur = upper_bound(all(idx[l_res]), r) - lower_bound(all(idx[l_res]), l);
        if (cur * 2 > len){
            return l_res;
        }
    }
    if (r_res != -1){
        int cur = upper_bound(all(idx[r_res]), r) - lower_bound(all(idx[r_res]), l);
        if (cur * 2 > len){
            return r_res;
        }
    }
    return -1;
}

void build(int node = 1, int l = 1, int r = n)
{
    if (l == r){
        tree[node] = ara[l];
        return;
    }
    build (left, l, mid);
    build(right, mid + 1, r);
    tree[node] = Merge(tree[left], tree[right], l, r);
}

int query(int x, int y, int node = 1, int l = 1, int r = n)
{
    if (l > y || r < x){
        return -1;
    }
    if (l >= x && r <= y){
        return tree[node];
    }
    return Merge(query(x, y, left, l, mid), query(x, y, right, mid + 1, r), x, y);
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;
    cin >> n >> c;
    for (int i = 1; i <= n; i++){
        cin >> ara[i];
        idx[ara[i]].pb(i);
    }
    build();
    int m;
    cin >> m;
    while (m--){
        int x, y;
        cin >> x >> y;
        int res = query(x, y);
        if (res == -1){
            cout << "no\n";
        }
        else{
            cout << "yes " << res << endl;
        }
    }
    return 0;
}

